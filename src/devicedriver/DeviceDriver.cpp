#include "FlashMemory.hpp"
#include "DeviceDriver.hpp"

DeviceDriver::DeviceDriver(FlashMemory& flashMemory) : flashMemory(flashMemory) {
}

char DeviceDriver::read(long address) {
    return flashMemory.read(address);
}

void DeviceDriver::write(long address, char data) {
    flashMemory.write(address, data);
}
