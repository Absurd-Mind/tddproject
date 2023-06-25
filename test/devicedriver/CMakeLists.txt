add_library(devicedriver_test OBJECT DeviceDriver.test.cpp)
target_include_directories(devicedriver_test PRIVATE ${CMAKE_SOURCE_DIR}/src/devicedriver/)
