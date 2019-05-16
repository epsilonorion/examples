cmake_minimum_required(VERSION 2.8)
project(FILEINPUT)

if(NOT DEFINED EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

file(GLOB SRC src/*.cpp)

add_executable(fileinput ${SRC})
