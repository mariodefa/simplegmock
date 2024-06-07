#include "Motors1.hpp"

Motors1 motors1 = Motors1();

Motors1::Motors1() : pwmPins{D5, D6, D7, D8, D1, D2, D3, D4}{} //GPIO 14,12,13,15, 5,4,0,2

void Motors1::setup1(){  
  for (int i = 0; i < N_PINS; i++) {
    pinMode(pwmPins[i], OUTPUT);
  }
  for (int i = 0; i < N_PINS; i++) {
    analogWrite(pwmPins[i], 0);
  }
}

void Motors1::applyMotorsCommands(Command1 *commands){
    for(int i=0;i<N_COMMANDS;i++){
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
