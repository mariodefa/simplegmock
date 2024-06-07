#include "UdpReader1.hpp"

void UdpReader1::createCommandListFromPacket(char* packet, Command1 *commands) {
    unsigned char* unsignedPacket = reinterpret_cast<unsigned char*>(packet);
    const int N_COMMANDS_L = PACKET_SIZE / CHUNK_SIZE;    
    for (int i = 0; i < N_COMMANDS_L; i++) {
        commands[i] = createCommandFromChunk(unsignedPacket + i * CHUNK_SIZE);
    }
}

Command1 UdpReader1::createCommandFromChunk(unsigned char* chunk) {
    int pwm = static_cast<int>(chunk[0]);
    Direction direction = Direction::forward;
    if(chunk[1]=='b'){
        direction = Direction::backward;
    }
    return Command1(pwm, direction);
}
