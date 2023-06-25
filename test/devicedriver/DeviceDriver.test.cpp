#include <DeviceDriver.cpp>
#include <catch2/catch_all.hpp>

TEST_CASE("Read after device init returns 0") {
    DeviceDriver deviceDriver;

    auto result = deviceDriver.read(0x03);

    REQUIRE(result == 0);
}

TEST_CASE("write") {
    DeviceDriver deviceDriver;

    deviceDriver.write(0x13, 37);
}
