#include "Motors1.hpp"

const int Motors1::pwmPins[] = {5, 4, 0, 2};

void Motors1::setup(){
  for (int i = 0; i < N_PINS; i++) {
    pinMode(pwmPins[i], OUTPUT);
  }
  for (int i = 0; i < N_PINS; i++) {
    analogWrite(pwmPins[i], 0);
  }
}

void Motors1::applyMotorsCommands(Command1 *commands){
    for(int i=0;i<N_COMANDS,i++){
        setMotorPWMs(i*2, commands[i]);
    }
}

//PRIVATES

void Motors1::setMotorPWMs(int motorIndex, Command1 command){
    switch(command.getDirection()){
        case forward:
            analogWrite(pwmPins[motorIndex], command.getPwm());
            analogWrite(pwmPins[motorIndex+1], 0);
            break;
        case backward:
            analogWrite(pwmPins[motorIndex], 0);
            analogWrite(pwmPins[motorIndex+1], command.getPwm());
            break;
    }
}
