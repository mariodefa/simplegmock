#ifndef MOTORS1_HPP
#define MOTORS1_HPP
#include "Udp1.hpp"
#include "MotorsInterface.hpp"
#include <Arduino.h> //for pinMode, analogWrite funcs and OUTPUT value

const int N_PINS = 8;

class Motors1 : public MotorsInterface{
public:
    Motors1();
    void setup1();
    void applyMotorsCommands(Command1 *commands) override;
private:
    const int pwmPins[N_PINS];
    void setMotorPWMs(int motorIndex, Command1 command);
};

extern Motors1 motors1;

#endif
