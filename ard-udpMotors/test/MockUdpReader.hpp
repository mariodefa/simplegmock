#ifndef MOCK_UDP_READER_HPP
#define MOCK_UDP_READER_HPP

#include "gmock/gmock.h"
#include "UdpReaderInterface.hpp"

class MockUdpReader : public UdpReaderInterface {
public:
    MockUdpReader(){};
    virtual ~MockUdpReader(){};
    MOCK_METHOD(void, createCommandListFromPacket,(char* packet, Command1 *commands), (override));
};

#endif