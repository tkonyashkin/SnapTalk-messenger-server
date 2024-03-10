cmake_minimum_required(VERSION 3.22)

project(SnapTalk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -fsanitize=address")

set(SRC_LIST src/core/messenger_service.cpp)

include_directories("${CMAKE_CURRENT_BINARY_DIR}/inc/")

add_executable(messenger_service ${SRC_LIST})

include(common.cmake)

get_filename_component(messenger_proto "src/api/protos/messenger.proto" ABSOLUTE)
get_filename_component(messenger_proto_path "${messenger_proto}" PATH)

set(messenger_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/src/api/messenger.pb.cc")
set(messenger_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/src/api/messenger.pb.h")
set(messenger_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/src/api/messenger.grpc.pb.cc")
set(messenger_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/src/api/messenger.grpc.pb.h")
add_custom_command(
      OUTPUT "${messenger_proto_srcs}" "${messenger_proto_hdrs}" "${messenger_grpc_srcs}" "${messenger_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/src/api"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/src/api"
        -I "${messenger_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${messenger_proto}"
      DEPENDS "${messenger_proto}")

include_directories("${CMAKE_CURRENT_BINARY_DIR}/src/api")

add_library(messenger_grpc_proto
  ${messenger_grpc_srcs}
  ${messenger_grpc_hdrs}
  ${messenger_proto_srcs}
  ${messenger_proto_hdrs})
target_link_libraries(messenger_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})
  
target_link_libraries(messenger_service
  messenger_grpc_proto
  absl::flags
  absl::flags_parse
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})
