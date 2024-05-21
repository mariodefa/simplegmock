#ifndef MOCK_MOTORS_HPP
#define MOCK_MOTORS_HPP

#include "gmock/gmock.h"
#include "MotorsInterface.hpp"

class MockMotors : public MotorsInterface{
public:
    MockMotors(){};
    virtual ~MockMotors(){};
    MOCK_METHOD(void, applyMotorsCommands, (Command1 *commands), (override));
};

#endif