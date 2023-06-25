#include <DeviceDriver.hpp>
#include <catch2/catch_all.hpp>
#include <fakeit.hpp>

using namespace fakeit;

TEST_CASE("Read after device init returns 0") {
    Mock<FlashMemory> flashMemory;
    When(Method(flashMemory,read)).Return(0);
    DeviceDriver deviceDriver(flashMemory.get());

    auto result = deviceDriver.read(0x03);

    REQUIRE(result == 0);
}

TEST_CASE("write") {
    Mock<FlashMemory> flashMemory;
    When(Method(flashMemory,read)).Return(37);
    When(Method(flashMemory,write)).AlwaysReturn();
    DeviceDriver deviceDriver(flashMemory.get());

    deviceDriver.write(0x13, 37);
    auto result = deviceDriver.read(0x13);

    REQUIRE(result == 37);
}
