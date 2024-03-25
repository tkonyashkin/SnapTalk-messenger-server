#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "../api/messenger.grpc.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;

using namespace messenger;

class MessengerServiceImpl final : public MessengerService::Service {
    private:
        std::mutex mutex;
        std::unordered_map<std::string, std::vector<ChatMessage>> chats;
        std::unordered_map<std::string, std::vector<ServerWriter<ChatMessage>*>> subscribers;

    public:
        Status SendMessage(ServerContext* context, const SentMessage* request, ChatMessage* response) override {
            std::lock_guard<std::mutex> lock(mutex);
            
            auto& messages = chats[request->chat_id()];
            auto message_id = std::to_string(messages.size());
            ChatMessage newMessage;
            messages.push_back(newMessage);
            newMessage.set_chat_id(request->chat_id());
            newMessage.set_id(message_id);
            newMessage.set_type(request->type());
            newMessage.set_content(request->content());
           

            for (auto* subscriber : subscribers[request->chat_id()]) {
                subscriber->Write(newMessage);
            }

            *response = newMessage;
            return Status::OK;
        }

        Status GetMessagesOffset(ServerContext* context, const GetMessagesOffsetRequest* request, GetMessagesOffsetResponse* response) override {
            std::lock_guard<std::mutex> lock(mutex);
            const auto& messages = chats[request->chat_id()];
            int64_t local_offset = request->offset();
            response->set_offset(messages.size() - local_offset);
            return Status::OK;
    }

        Status GetMessagesConversion(ServerContext* context, const GetMessagesConversionRequest* request, GetMessagesConversionResponse* response) override {
            std::lock_guard<std::mutex> lock(mutex);
            const auto& messages = chats[request->chat_id()];
            int64_t offset = request->offset();
            int32_t count = request->count();
            for (int64_t i = offset; i < std::min(offset + count, static_cast<int64_t>(messages.size())); ++i) {
                *response->add_messages() = messages[i];
            }
            return Status::OK;
        }

        Status GetNewMessages(ServerContext* context, const GetNewMessagesRequest* request, ServerWriter<ChatMessage>* writer) override {
            std::string chatId = request->chat_id();
            {
                std::lock_guard<std::mutex> lock(mutex);
                subscribers[chatId].push_back(writer);
            }
            try {
                while (!context->IsCancelled()) {
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
            } catch (...) {
                std::cerr << "An error occurred, possibly client disconnected" << std::endl;
            }

            {
                std::lock_guard<std::mutex> lock(mutex);
                auto& subs = subscribers[chatId];
                auto it = std::find(subs.begin(), subs.end(), writer);
                if (it != subs.end()) {
                    subs.erase(it);
                }
            }

            return Status::OK;
        }


};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    MessengerServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
    