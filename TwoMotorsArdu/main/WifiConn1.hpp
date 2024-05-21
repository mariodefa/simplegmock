#ifndef WIFICONN1_HPP
#define WIFICONN1_HPP

#include <Arduino.h>  // for Serial.println
#include <ESP8266WiFi.h> // for WiFi connection
#include "Udp1.hpp"  //to start UDP server after connection
#include "WiFiUDPReal.hpp"  //to use real calls to hardware
#include "SerialReal.hpp"  //to use real calls to hardware

UdpReader1 udpReader1 = UdpReader1();
WiFiUDPReal wiFiUDPReal = WiFiUDPReal();
SerialReal serialReal = SerialReal();

class WifiConn1 {
    public:
        static void connectToDomesticWifi(String wifiName, String wifiPass);
        static bool isConnected();
    private:
        static bool connected;
};

#endif
