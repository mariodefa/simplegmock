#ifndef MOCK_WIFI_UDP_HPP
#define MOCK_WIFI_UDP_HPP

#include "gmock/gmock.h"
#include "WiFiUDPInterface.hpp"

class MockWiFiUDP : public WiFiUDPInterface {
public:
    MockWiFiUDP(){};
    virtual ~MockWiFiUDP(){};
    MOCK_METHOD(void,begin,(unsigned int port),(override));
    MOCK_METHOD(int,parsePacket,(),(override));
    MOCK_METHOD(int,read,(char* buffer, size_t length),(override));
    MOCK_METHOD(const char*, remoteIP, (), (override));
    MOCK_METHOD(int, remotePort, (), (override));
};

#endif
