#include "Command1.hpp"

Command1::Command1() : pwm(0), direction(Direction::forward) {}

Command1::Command1(int pwm, Direction direction) : pwm(pwm), direction(direction) {}

int Command1::getPwm() {
    return pwm;
}

Direction Command1::getDirection() {
    return direction;
}
