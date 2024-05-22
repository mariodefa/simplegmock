#ifndef WIFIUDP_INTERFACE_HPP
#define WIFIUDP_INTERFACE_HPP

class WiFiUDPInterface {
public:
    virtual void begin(unsigned int port){};
    virtual int parsePacket() = 0;
    virtual int read(char* buffer, int length) = 0;
    virtual const char* remoteIPstring() = 0;
    virtual int remotePort() = 0;
};

#endif