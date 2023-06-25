#pragma once

class FlashMemory {
public:
    virtual unsigned char read(unsigned long address) = 0;
    virtual void write(unsigned long address, unsigned char data) = 0;
};

inline unsigned long CONTROL_ADDRESS = 0x00;
inline unsigned char PROGRAM = 0x40;