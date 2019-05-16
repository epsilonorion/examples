cmake_minimum_required(VERSION 2.8)
project(NESTED_CLASSES_TEST)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)
file(GLOB SRC src/*.cpp)

add_executable(6_nestedClassesTest ${SRC})
