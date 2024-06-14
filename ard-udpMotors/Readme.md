# Intro
Arduino app to define a UDP server who receives packets with motor-commands inside  

## Folders
To open arduino project go to main and double click **main.ino**  
Other folders are for running tests using gtest  

## GTest
to run tests with gtest follow **tests.md** directions  

## Use
turn on esp8266  
connect phone to azucarito  
go to 192.168.4.1  
enter ssid and password of your domestic wifi  
open fing and look for MAC address
save that ip address  
paste in udpMotors.ts destination ip  
copy paste vendors inside **node_modules/gamecontroller/lib**