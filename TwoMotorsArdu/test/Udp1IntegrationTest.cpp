#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Udp1.hpp"
#include "UdpReader1.hpp"
#include "MockSerial.hpp"
#include "MockWiFiUDP.hpp"

using ::testing::_;
using ::testing::Return;

//mocks
MockSerial mockSerial_2;
MockWiFiUDP mockWiFiUDP_2;
MockMotors mockMotors_2;

//real
UdpReader1 udpReader1_2 = UdpReader1();

void SetUpMocks() {
    Udp1::linkDependencies(&udpReader1_2, &mockMotors);
    Udp1::startUdpSocket(&mockWiFiUDP, &mockSerial);
}

//received package 0x7F 'b' 'd' 'f' it is translated to 255 backwards 100 forward
TEST(Udp1Test, HandleUdpPcksTest) {
    //fixtures
    char incomingFix[PACKET_SIZE] = {'\x7F', 'b', 'd', 'f'};
    //Captors
    Command1 actual[N_COMMANDS];
    //EXPECTED
    Command1 expected[N_COMMANDS] = {Command1(255,Direction::backward),Command1(100,Direction::forward)};

    //MOCKs
    //WiFiUDP1
    EXPECT_CALL(mockWiFiUDP, parsePacket()).WillOnce(Return(PACKET_SIZE));
    EXPECT_CALL(mockWiFiUDP, read(_, PACKET_SIZE))
        .WillOnce(DoAll(
            ::testing::SetArrayArgument<0>(incomingFix, incomingFix + PACKET_SIZE), //forze return incomingFix value inside incomingPacket param
            Return(PACKET_SIZE)
        ));    
    //Motors1
    EXPECT_CALL(mockMotors, applyMotorsCommands(_)).Times(1); 

    //CAPTURE
    //UdpReader1
    EXPECT_CALL(UdpReader1, createCommandListFromPacket(
        ::testing::_, _))
        .WillOnce(DoAll(
            WithArgs<1>(SaveArg<1>(&actual)), //Capture argument 1, commands
            Return()
        ));

    //test
    Udp1::handleUdpPcks();

    //check
    for (int i = 0; i < N_COMMANDS; ++i) {
        EXPECT_EQ(actual[i].getPWM(), expected[i].getPWM());
        EXPECT_EQ(actual[i].getDirection(), expected[i].getDirection());
    }
}

int main(int argc, char **argv) {
    SetUpMocks();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
