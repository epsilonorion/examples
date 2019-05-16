cmake_minimum_required(VERSION 2.8)
project(sockets)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(server src/server.cpp)
add_executable(client src/client.cpp)

