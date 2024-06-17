#include "Motors1.hpp"

Motors1 motors1 = Motors1();

Motors1::Motors1() : pwmPins{D5, D6, D7, D8, D1, D2, D3, D4}{} //GPIO 14,12,13,15, 5,4,0,2

void Motors1::setup1(){  
  servo1.attach(D0);//GPIO 16
  servo2.attach(A0);//ADC0
  for (int i = 0; i < N_PINS; i++) {
    pinMode(pwmPins[i], OUTPUT);
  }
  servo1.write(90);
  servo2.write(90);
  for (int i = 0; i < N_PINS; i++) {
    analogWrite(pwmPins[i], 0);
  }
}

void Motors1::applyMotorsCommands(Command1 *commands){
    for(int i=0;i<(N_COMMANDS-2);i++){
        setMotorPWMs(i*2, commands[i]);
    }
    servo1.write(commands[N_COMMANDS-2].getPwm());
    servo2.write(commands[N_COMMANDS-1].getPwm());
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
