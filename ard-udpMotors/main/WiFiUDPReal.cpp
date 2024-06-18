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
    static char ipStr[16];//By using a static buffer, we ensure that the IP address is not lost or corrupted when the function exits
    String ipString = udp.remoteIP().toString();
    strncpy(ipStr, ipString.c_str(), sizeof(ipStr) - 1);//copy it so it will remain during the entire execution, strncpy(dest,src,length)
    ipStr[sizeof(ipStr) - 1] = '\0';//end array with null
    return ipStr;
}

int WiFiUDPReal::remotePort() {
    return static_cast<int>(udp.remotePort());//from uint16_t
}
