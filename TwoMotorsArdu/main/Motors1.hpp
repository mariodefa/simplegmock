#ifndef MOTORS1_HPP
#define MOTORS1_HPP
#include "Udp1.hpp"
#include "MotorsInterface.hpp"

const int N_PINS = 4;

class Motors1 : public MotorsInterface{
public:
    Motors1() {};
    void setup() override;
    void applyMotorsCommands(Command1 *commands) override;
private:
    const int pwmPins[];
    void setMotorPWMs(int motorIndex, Command1 command);
};

Motors1 motors1 = Motors1();

#endif
