cmake_minimum_required(VERSION 2.8)
project(STANDARD_TEST)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(1_standard)
add_subdirectory(2_header)
add_subdirectory(3_standard_class)
add_subdirectory(4_header_class)
add_subdirectory(5_separate_class)
add_subdirectory(6_nested_classes)
add_subdirectory(7_pass_classes)
add_subdirectory(8_poly_classes)
