#include "WiFiUDPReal.hpp"

void WiFiUDPReal::begin(unsigned int port) {
    udp.begin(port);
}

int WiFiUDPReal::parsePacket() {
    return udp.parsePacket();
}

int WiFiUDPReal::read(char* buffer, int length) {
    return udp.read(buffer, static_cast<size_t>(length));
}

const char* WiFiUDPReal::remoteIPstring() {
    return udp.remoteIP().toString().c_str();
}

int WiFiUDPReal::remotePort() {
    return static_cast<int>(udp.remotePort());//from uint16_t
}
