#ifndef UDP1_HPP
#define UDP1_HPP

#include "Command1.hpp"
#include "UdpReaderInterface.hpp"
#include "MotorsInterface.hpp"
#include "WiFiUDPInterface.hpp"
#include "SerialInterface.hpp"
#include "UDPConstants.hpp"

//using UDP packets will arrived in wrong order, get lost. but it will use less bandwidth
class Udp1 {
public:
    static void linkDependencies(UdpReaderInterface *udpReader1, MotorsInterface *motors1);
    static void startUdpSocket(WiFiUDPInterface *udpInstance, SerialInterface *serInstance);
    static void handleUdpPcks();
private:
    static UdpReaderInterface *udpRe;
    static MotorsInterface *mot;
    static SerialInterface *ser;
    static WiFiUDPInterface *udp;
    static char incomingPacket[PACKET_SIZE+1];
    static Command1 commands[N_COMMANDS];
};

#endif
