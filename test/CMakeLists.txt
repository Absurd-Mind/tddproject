cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(FakeIt REQUIRED CONFIG)
find_package(Catch2 REQUIRED CONFIG)

include_directories(${Catch2_INCLUDE_DIR})
include_directories(${fakeit_INCLUDE_DIR})

add_subdirectory(bowling/)
add_subdirectory(devicedriver/)

add_executable(test_all null.cpp)
target_link_libraries(test_all PUBLIC
    bowling_test
    devicedriver_test
)
target_link_libraries(test_all PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(test_all)
