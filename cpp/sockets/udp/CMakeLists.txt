cmake_minimum_required(VERSION 2.8)
project(udp_sockets)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(udp_server src/udp_server.cpp)
add_executable(udp_client src/udp_client.cpp)

