#include "Motors1.hpp"

Motors1 motors1 = Motors1();

/*
ESP32-S3 WROOM-1-N16R8
ESP32-S3-DevKitC-1
Motor 1: GPIO 5 , GPIO 6
Motor 2: GPIO 7 , GPIO 15
Motor 3: GPIO 11 , GPIO 12
Motor 4: GPIO 13 , GPIO 14
Servo 1: GPIO 16
Servo 2: GPIO 17
*/

Motors1::Motors1() : pwmPins{5, 6, 7, 15, 11, 12, 13, 14}{}

void Motors1::setup1(){  
  servo1.attach(16);
  servo2.attach(17);
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
