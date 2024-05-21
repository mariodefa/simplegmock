#include "WiFiUDPReal.hpp"

void WiFiUDPReal::begin(unsigned int port) {
    udp.begin(port);
}

int WiFiUDPReal::parsePacket() {
    return udp.parsePacket();
}

int WiFiUDPReal::read(char* buffer, size_t length) {
    return udp.read(buffer, length);
}

IPAddress WiFiUDPReal::remoteIP() {
    return udp.remoteIP();
}

uint16_t WiFiUDPReal::remotePort() {
    return udp.remotePort();
}
