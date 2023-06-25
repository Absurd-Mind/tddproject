#pragma once

class FlashMemory {
public:
    virtual char read(long address) = 0;
    virtual void write(long address, char data) = 0;
};
