#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Udp1.hpp"
#include "UdpReader1.hpp"
#include "MockSerial.hpp"
#include "MockWiFiUDP.hpp"
#include "MockMotors.hpp"

using ::testing::_;
using ::testing::Return;

class Udp1IntegrationTest : public ::testing::Test {
protected:
    //mocks
    MockSerial mockSerial_2;
    MockWiFiUDP mockWiFiUDP_2;
    MockMotors mockMotors_2;

    //real
    UdpReader1 udpReader1_2 = UdpReader1();

    void SetUp() override {
        Udp1::linkDependencies(&udpReader1_2, &mockMotors_2);
        Udp1::startUdpSocket(&mockWiFiUDP_2, &mockSerial_2);
    }

    void TearDown() override {        
        mockSerial_2.~MockSerial();
        mockWiFiUDP_2.~MockWiFiUDP();
        mockMotors_2.~MockMotors();
        udpReader1_2.~UdpReader1();
    }
};

//received package 0xFF 'b' 'd' 'f' it is translated to 255 backwards 100 forward
TEST_F(Udp1IntegrationTest, HandleUdpPcksTest) {
    //fixtures
    char incomingFix[PACKET_SIZE] = {'\xFF', 'b', 'd', 'f'};
    //Captors
    Command1 actual[N_COMMANDS] = {Command1(),Command1(),Command1(),Command1()};
    Command1* captured_commands = nullptr;
    //EXPECTED
    Command1 expected[N_COMMANDS] = {Command1(255,Direction::backward),Command1(100,Direction::forward)};

    //MOCKs
    //WiFiUDP1
    EXPECT_CALL(mockWiFiUDP_2, parsePacket()).WillOnce(Return(PACKET_SIZE));
    EXPECT_CALL(mockWiFiUDP_2, read(_, PACKET_SIZE))
        .WillOnce(::testing::DoAll(
            ::testing::SetArrayArgument<0>(incomingFix, incomingFix + PACKET_SIZE), //forze return incomingFix value inside incomingPacket param
            Return(PACKET_SIZE)
        ));    
    //Motors1
    //CAPTURE
    EXPECT_CALL(mockMotors_2, applyMotorsCommands(_))
        .WillOnce(::testing::DoAll(
            ::testing::WithArgs<0>(::testing::SaveArg<0>(&captured_commands)), //Capture argument 1, commands
            Return()
        ));; 

    //test
    Udp1::handleUdpPcks();

    //check
    if (captured_commands != nullptr) {
        std::copy(captured_commands, captured_commands + N_COMMANDS, actual);
    }
    for (int i = 0; i < N_COMMANDS; ++i) {
        EXPECT_EQ(actual[i].getPwm(), expected[i].getPwm());
        EXPECT_EQ(actual[i].getDirection(), expected[i].getDirection());
    }
}

TEST_F(Udp1IntegrationTest, ReceivePacketSmallerThanExpected) {
    //MOCK
    EXPECT_CALL(mockWiFiUDP_2, parsePacket()).WillOnce(Return(6)); //packet size smaller than expected
    //EXPECTED
    EXPECT_CALL(mockWiFiUDP_2, read(_, _)).Times(0);
    EXPECT_CALL(mockMotors_2, applyMotorsCommands(_)).Times(0);

    //test
    Udp1::handleUdpPcks();
}

TEST_F(Udp1IntegrationTest, ReceivePacketLargerThanExpected) {
    //MOCK
    EXPECT_CALL(mockWiFiUDP_2, parsePacket()).WillOnce(Return(10)); //packet size bigger than expected
    //EXPECTED
    EXPECT_CALL(mockWiFiUDP_2, read(_, _)).Times(0);
    EXPECT_CALL(mockMotors_2, applyMotorsCommands(_)).Times(0);

    //test
    Udp1::handleUdpPcks();
}
