#pragma once

#include "FlashMemory.hpp"

class DeviceDriver {
public:
    DeviceDriver(FlashMemory& flashMemory);

    virtual unsigned char read(long address);
    virtual void write(long address, unsigned char data);

private:
    FlashMemory& flashMemory;
};
