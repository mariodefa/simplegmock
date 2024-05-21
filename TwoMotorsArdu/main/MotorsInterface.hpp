#ifndef MOTORS_INTERFACE_HPP
#define MOTORS_INTERFACE_HPP

class MotorsInterface {
public:
    virtual void applyMotorsCommands(Command1 *commands) = 0;
};

#endif