#ifndef MOCK_MOTORS_HPP
#define MOCK_MOTORS_HPP

#include "MotorsInterface.hpp"

class MockMotors : public MotorsInterface{
public:
    MockMotors(){};
    void applyMotorsCommands(Command1 *commands) override {
        //do nothing
    };
};

#endif