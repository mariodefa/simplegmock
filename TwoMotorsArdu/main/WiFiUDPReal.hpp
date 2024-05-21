#ifndef WIFI_UDP_REAL_HPP
#define WIFI_UDP_REAL_HPP

#include "WiFiUDPInterface.hpp"
#include <WiFiUdp.h> //arduino library for udp sockets

class WiFiUDPReal : public WiFiUDPInterface {
public:
    WiFiUDPReal() {};
    void begin(unsigned int port) override;
    int parsePacket() override;
    int read(char* buffer, size_t length) override;
    IPAddress remoteIP() override;
    uint16_t remotePort() override;

private:
    WiFiUDP udp;
};

#endif
