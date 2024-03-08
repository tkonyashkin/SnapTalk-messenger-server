#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

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
};
    