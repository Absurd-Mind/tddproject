#include <DeviceDriver.hpp>
#include <catch2/catch_all.hpp>
#include <fakeit.hpp>
#include <string>

using namespace fakeit;

TEST_CASE("Read after device startup returns 0") {
    // Arrange
    auto address = GENERATE(range(1, 120));
    Mock<FlashMemory> flashMemory;
    When(Method(flashMemory,read)).Return(0);
    DeviceDriver deviceDriver(flashMemory.get());

    // Act
    auto result = deviceDriver.read(address);

    // Assert
    REQUIRE(result == 0);
}

TEST_CASE("reading data after writing returns the same data") {
    // Arrange
    auto address = GENERATE(values({1, 7, 120}));
    auto data = GENERATE(values({0x00, 0x01, 0x37, 0xFF}));
    Mock<FlashMemory> flashMemory;

    SECTION("address=" + std::to_string(address) + ", data=" + std::to_string(data)) {
        When(Method(flashMemory, read).Using(0x00)).Return(1 << 6);
        When(Method(flashMemory, read).Using(address)).Return(data);
        When(Method(flashMemory, write)).AlwaysReturn();
        DeviceDriver deviceDriver(flashMemory.get());

        // Act
        deviceDriver.write(address, data);
        auto result = deviceDriver.read(address);

        // Assert
        REQUIRE(result == data);
        Verify(Method(flashMemory, write).Using(0x00, 0x40)).Once();
        Verify(Method(flashMemory, write).Using(address, data)).Once();
    }
}

TEST_CASE("Ready bit is only set on the second read") {
    // Arrange
    unsigned long address = 0x04;
    unsigned char data = 0x37;
    Mock<FlashMemory> flashMemory;
    When(Method(flashMemory, read).Using(0x00))
        .Return(0)
        .Return(1 << 6);
    When(Method(flashMemory, write)).AlwaysReturn();
    DeviceDriver deviceDriver(flashMemory.get());

    // Act
    deviceDriver.write(address, data);

    // Assert
    Verify(Method(flashMemory, write).Using(0x00, 0x40)).Once();
    Verify(Method(flashMemory, write).Using(address, data)).Once();
    Verify(Method(flashMemory, read).Using(0x00)).Exactly(2);
}
