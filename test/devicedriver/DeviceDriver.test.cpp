#include <DeviceDriver.cpp>
#include <catch2/catch_all.hpp>

TEST_CASE("drive device") {
    DeviceDriver deviceDriver;

    auto result = deviceDriver.read(0x03);
}
