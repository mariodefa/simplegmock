#ifndef COMMAND1_HPP
#define COMMAND1_HPP

enum Direction { 
    forward = 'f', 
    backward = 'b'
};

class Command1 {
public:
    Command1();
    Command1(int pwm, Direction direction);
    int getPwm();
    Direction getDirection();
private:
    int pwm;
    Direction direction;
};

#endif
