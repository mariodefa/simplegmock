#ifndef UDPREADER1_HPP
#define UDPREADER1_HPP

#include "Command1.hpp"
#include "UdpReaderInterface.hpp"

const int CHUNK_SIZE = 2;
const int PACKET_SIZE = 8; //remove it

class UdpReader1 : public UdpReaderInterface{
public:
    UdpReader1() {};
    void createCommandListFromPacket(char* packet, Command1 *commands) override;
    Command1 createCommandFromChunk(unsigned char* chunk); //public only for running tests 
};

#endif
