#ifndef SERIAL_REAL_HPP
#define SERIAL_REAL_HPP

#include <Arduino.h> //for serial print
#include "SerialInterface.hpp"

class SerialReal : public SerialInterface {
public:
    SerialReal() {};
    void println(String message) override;
};

#endif
