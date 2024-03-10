#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

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
    public:
        Status SendMessage(ServerContext* context, const SentMessage* request, ChatMessage* response) override {
            response->set_id("123");
            response->set_type(messenger::MessageType::TEXT);
            response->set_content("Hello, world!");
            return Status::OK;
        }

        Status GetMessagesOffset(ServerContext* context, const GetMessagesOffsetRequest* request, GetMessagesOffsetResponse* response) override {
        response->set_offset(50);
        return Status::OK;
        }

        Status GetMessagesConversion(ServerContext* context, const GetMessagesConversionRequest* request, GetMessagesConversionResponse* response) override {
            for (int i = 0; i < request->count(); ++i) {
                ChatMessage* message = response->add_messages();
                message->set_id("123");
                message->set_type(messenger::MessageType::TEXT);
                message->set_content("Hello, world!");
            }
        return Status::OK;
        }

        Status GetNewMessages(ServerContext* context, const GetNewMessagesRequest* request, ::grpc::ServerWriter<ChatMessage>* writer) override {
    int i = 0;
    while (true) {
        ChatMessage message;
        message.set_id(std::to_string(i++));
        message.set_type(messenger::MessageType::TEXT);
        message.set_content("Hello, world!");
        writer->Write(message);

        std::this_thread::sleep_for(std::chrono::seconds(10));
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
    