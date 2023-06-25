cmake_minimum_required(VERSION 3.15)
project(tddproject CXX)

if (NOT BUILD_TESTING STREQUAL OFF)
    enable_testing()
    add_subdirectory(test)
endif()

add_subdirectory(src/)

