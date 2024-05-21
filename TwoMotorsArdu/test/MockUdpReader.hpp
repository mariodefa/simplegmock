#ifndef MOCK_UDP_READER_HPP
#define MOCK_UDP_READER_HPP

#include "UdpReaderInterface.hpp"

class MockUdpReader : public UdpReaderInterface {
public:
    MockUdpReader(){};
    void createCommandListFromPacket(char* packet, Command1 *commands) override {
        //do nothing
    };
};

#endif