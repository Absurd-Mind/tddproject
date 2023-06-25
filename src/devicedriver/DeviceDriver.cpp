#include "FlashMemory.hpp"
#include "DeviceDriver.hpp"

DeviceDriver::DeviceDriver(FlashMemory& flashMemory) : flashMemory(flashMemory) {
}

unsigned char DeviceDriver::read(unsigned long address) {
    return flashMemory.read(address);
}

void DeviceDriver::write(unsigned long address, unsigned char data) {
    flashMemory.write(CONTROL_ADDRESS, PROGRAM);
    flashMemory.write(address, data);
    auto result = flashMemory.read(CONTROL_ADDRESS);
    if ((result & (1 << 6)) == 0) {
        result = flashMemory.read(CONTROL_ADDRESS);
    }
}
