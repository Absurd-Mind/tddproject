add_library(bowling_test OBJECT bowling.test.cpp)
target_include_directories(bowling_test PRIVATE ${CMAKE_SOURCE_DIR}/src/bowling/)
