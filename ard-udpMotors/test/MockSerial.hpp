#ifndef MOCK_SERIAL_HPP
#define MOCK_SERIAL_HPP

#include "gmock/gmock.h"
#include "SerialInterface.hpp"

class MockSerial : public SerialInterface {
public:
    MockSerial(){};
    virtual ~MockSerial(){};
    MOCK_METHOD(void, println,(const char* message), (override));
};

#endif