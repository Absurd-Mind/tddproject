#pragma once

#include "FlashMemory.hpp"

class DeviceDriver {
public:
    DeviceDriver(FlashMemory& flashMemory);

    virtual char read(long address);
    virtual void write(long address, char data);

private:
    FlashMemory& flashMemory;
};
