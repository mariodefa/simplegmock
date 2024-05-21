#ifndef UDP1_HPP
#define UDP1_HPP

#include "Command1.hpp"
#include "UdpReader1.hpp"
#include "WiFiUDPInterface.hpp"
#include "SerialInterface.hpp"

const int N_COMMANDS = 2; // one command per motor
const int PACKET_SIZE = 8;

class Udp1 {
public:
    static void linkDependencies(UdpReader1 *udpReader1, Motors1 *motors1);
    static void startUdpSocket(WiFiUDPInterface *udpInstance, SerialInterface *serInstance);
    static void handleUdpPcks();
private:
    static UdpReader1 *udpRe;
    static Motors1 *mot;
    static SerialInterface *ser;
    static WiFiUDPInterface *udp;
    static char incomingPacket[PACKET_SIZE];
    static Command1 commands[N_COMMANDS];
};

#endif
