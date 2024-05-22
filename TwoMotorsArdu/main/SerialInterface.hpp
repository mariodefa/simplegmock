#ifndef SERIAL_INTERFACE_HPP
#define SERIAL_INTERFACE_HPP

class SerialInterface {
public:
    virtual void println(const char* message) = 0;
};

#endif
