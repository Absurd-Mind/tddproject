

#include "FlashMemory.hpp"

class DeviceDriver {
public:
    DeviceDriver(FlashMemory& flashMemory) : flashMemory(flashMemory) {

    }

    char read(long address) {
        return flashMemory.read(address);
    }

    void write(long address, char data) {
        flashMemory.write(address, data);
    }
private:
    FlashMemory& flashMemory;
};
