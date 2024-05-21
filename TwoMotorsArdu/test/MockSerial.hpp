#ifndef MOCK_SERIAL_HPP
#define MOCK_SERIAL_HPP

#include "SerialInterface.hpp"

class MockSerial : public SerialInterface {
public:
    MockSerial(){};
    void println(String message) override{
        //do nothing
    };
};

#endif