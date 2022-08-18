cmake_minimum_required(VERSION 3.22.1)

add_library(test-lib SHARED test-lib.c)

target_link_libraries(test-lib)