#pragma once

class FlashMemory {
public:
    virtual unsigned char read(long address) = 0;
    virtual void write(long address, unsigned char data) = 0;
};
