cmake_minimum_required(VERSION 3.22)

project(SnapTalk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -fsanitize=address")

set(SRC_LIST source/main.cpp)

include_directories(include/)

add_executable(main ${SRC_LIST})

include(common.cmake)

get_filename_component(messenger_proto "sourse/messenger.proto" ABSOLUTE)
get_filename_component(messenger_proto_path "${messenger_proto}" PATH)

set(messenger_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/messenger.pb.cc")
set(messenger_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/messenger.pb.h")
set(messenger_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/messenger.grpc.pb.cc")
set(messenger_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/messenger.grpc.pb.h")
add_custom_command(
      OUTPUT "${messenger_proto_srcs}" "${messenger_proto_hdrs}" "${messenger_grpc_srcs}" "${messenger_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${messenger_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${messenger_proto}"
      DEPENDS "${messenger_proto}")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_library(messenger_grpc_proto
  ${messenger_grpc_srcs}
  ${messenger_grpc_hdrs}
  ${messenger_proto_srcs}
  ${messenger_proto_hdrs})
target_link_libraries(messenger_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

add_library(messenger_helper
  "helper.h"
  "helper.cc")
target_link_libraries(messenger_helper
  messenger_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

foreach(_target
  messenger_client messenger_server)
  add_executable(${_target}
    "${_target}.cc")
  target_link_libraries(${_target}
    messenger_grpc_proto
    messenger_helper
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()
