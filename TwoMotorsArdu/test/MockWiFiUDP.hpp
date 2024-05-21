#ifndef MOCK_WIFI_UDP_HPP
#define MOCK_WIFI_UDP_HPP

#include "WiFiUDPInterface.hpp"

class MockWiFiUDP : public WiFiUDPInterface {
public:
    MockWiFiUDP(){};
    void begin(unsigned int port) override {
        //do nothing
    }

    int parsePacket() override {
        return 0; //dummy
    }

    int read(char* buffer, size_t length) override {
        return 0; //dummy
    }

    const char* remoteIP() override {
        return ""; //dummy
    }

    int remotePort() override {
        return 0; //dummy
    }
};

#endif
