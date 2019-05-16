cmake_minimum_required(VERSION 2.8)
project(CLASS_TEST)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SRC src/*.cpp)

add_executable(3_standardClassTest ${SRC})
