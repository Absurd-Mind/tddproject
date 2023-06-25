#include "FlashMemory.hpp"
#include "DeviceDriver.hpp"

DeviceDriver::DeviceDriver(FlashMemory& flashMemory) : flashMemory(flashMemory) {
}

unsigned char DeviceDriver::read(long address) {
    return flashMemory.read(address);
}

void DeviceDriver::write(long address, unsigned char data) {
    flashMemory.write(address, data);
}
