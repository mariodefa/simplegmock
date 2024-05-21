#ifndef WIFIUDP_INTERFACE_HPP
#define WIFIUDP_INTERFACE_HPP

#include <IPAddress.h>

class WiFiUDPInterface {
public:
    virtual void begin(unsigned int port){};
    virtual int parsePacket() = 0;
    virtual int read(char* buffer, size_t length) = 0;
    virtual IPAddress remoteIP() = "";
    virtual uint16_t remotePort() = 0;
};

#endif