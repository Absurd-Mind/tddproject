#pragma once

#include "FlashMemory.hpp"

class DeviceDriver {
public:
    DeviceDriver(FlashMemory& flashMemory);

    virtual unsigned char read(unsigned long address);
    virtual void write(unsigned long address, unsigned char data);

private:
    FlashMemory& flashMemory;
};
