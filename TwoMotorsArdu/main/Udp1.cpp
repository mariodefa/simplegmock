#include "Udp1.hpp"

WiFiUDPInterface * Udp1::udp = nullptr;
const unsigned int UDP_PORT = 4210;
char Udp1::incomingPacket[PACKET_SIZE+1];
Command1 Udp1::commands[N_COMMANDS];

void Udp1::linkDependencies(UdpReader1 *udpReader1, Motors1 *motors1){
    udpRe = udpReader1;
    mot = motors1;
}

void Udp1::startUdpSocket(WiFiUDPInterface *udpInstance, SerialInterface *serInstance) {
    ser = serInstance;
    udp = udpInstance;
    udp->begin(UDP_PORT);
    ser->println("UDP listo para recibir");
    incomingPacket[PACKET_SIZE] = '\0'; // end of data flag
}

void Udp1::handleUdpPcks() {
    int packetSize = udp->parsePacket();
    if (packetSize && packetSize == PACKET_SIZE)
    {
        //Serial.printf("Recibido %d bytes desde %s, puerto %d\n", packetSize, udp->remoteIP().toString().c_str(), udp->remotePort());
        int len = udp->read(incomingPacket, PACKET_SIZE);        
        ser->println("Mensaje UDP:\n");
        ser->println(incomingPacket);
        udpRe->createCommandListFromPacket(incomingPacket, commands); //new commands saved in commands array
        mot->applyMotorsCommands(commands); //write pwms from commands array into motors
    }
}
