#ifndef UDPREADER1_HPP
#define UDPREADER1_HPP

#include "Command1.hpp"
#include "UdpReaderInterface.hpp"
#include "UDPConstants.hpp"

class UdpReader1 : public UdpReaderInterface{
public:
    UdpReader1() {};
    void createCommandListFromPacket(char* packet, Command1 *commands) override;
    Command1 createCommandFromChunk(unsigned char* chunk); //public only for running tests 
};

#endif
