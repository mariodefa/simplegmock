#ifndef UDP_READER_INTERFACE_HPP
#define UDP_READER_INTERFACE_HPP

class UdpReaderInterface {
public:
    virtual void createCommandListFromPacket(char* packet, Command1 *commands) = 0;
};

#endif