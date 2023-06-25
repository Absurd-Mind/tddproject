#pragma once

class FlashMemory {
public:
    virtual unsigned char read(long address) = 0;
    virtual void write(long address, unsigned char data) = 0;
};

inline long CONTROL_ADDRESS = 0x00;
inline unsigned char PROGRAM = 0x40;