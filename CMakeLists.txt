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

