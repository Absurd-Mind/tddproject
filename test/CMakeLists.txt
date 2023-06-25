cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(Catch2 REQUIRED CONFIG)
include_directories(${Catch2_INCLUDE_DIR})
# target_link_libraries(test_hello GTest::gtest GTest::gtest_main hello)

add_subdirectory(bowling/)

add_executable(test_all null.cpp)
target_link_libraries(test_all PUBLIC
    bowling_test
    
)
target_link_libraries(test_all PRIVATE Catch2::Catch2WithMain)
