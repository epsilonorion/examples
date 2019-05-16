cmake_minimum_required(VERSION 2.8)
project(version1)

if(NOT DEFINED EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

################################################################################
# Set Compiler flag for which method
################################################################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DVER=4 -Wall -pedantic -pthread")


################################################################################
# Set Compiler flag for C+11 support
################################################################################
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


file(GLOB SRC src/*.cpp)

add_executable(version1 ${SRC})
