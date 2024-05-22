#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Udp1.hpp"
#include "MockSerial.hpp"
#include "MockWiFiUDP.hpp"
#include "MockMotors.hpp"
#include "MockUdpReader.hpp"

using ::testing::_;
using ::testing::Return;

//mocks
MockSerial mockSerial_1;
MockWiFiUDP mockWiFiUDP_1;
MockUdpReader mockUdpReader_1;
MockMotors mockMotors_1;

void SetUpMocks() {
    Udp1::linkDependencies(&mockUdpReader_1, &mockMotors_1);
    Udp1::startUdpSocket(&mockWiFiUDP_1, &mockSerial_1);
}

//begin is called inside startUdpSocket
TEST(Udp1Test, StartUdpSocketTest) {
    //EXPECTs
    EXPECT_CALL(mockWiFiUDP_1, begin(_));

    //test
    Udp1::startUdpSocket(&mockWiFiUDP_1, &mockSerial_1);
}

//parsePacket and read are called inside HandleUdpPcksTest
TEST(Udp1Test, HandleUdpPcksCalledTest) {
    //EXPECTs
    EXPECT_CALL(mockWiFiUDP_1, parsePacket()).WillOnce(Return(8));
    EXPECT_CALL(mockWiFiUDP_1, read(_, _));

    //test
    Udp1::handleUdpPcks();
}

//packet received is sent to UdpReader
TEST(Udp1Test, HandleUdpPcksTest) {
    //Captors
    char actual[PACKET_SIZE] = {'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f'};
    char* captured_packet = nullptr;
    //EXPECTED
    char expected[PACKET_SIZE] = {'\x7F', 'b', 'd', 'f', '\0', 'f', '\0', 'f'};

    //MOCKs
    //WiFiUDP1
    EXPECT_CALL(mockWiFiUDP_1, parsePacket()).WillOnce(Return(PACKET_SIZE));
    EXPECT_CALL(mockWiFiUDP_1, read(_, PACKET_SIZE))
        .WillOnce(::testing::DoAll(
            ::testing::SetArrayArgument<0>(expected, expected + PACKET_SIZE), //forze return "expected" value inside incomingPacket param
            Return(PACKET_SIZE)
        ));
    //UdpReader1
    EXPECT_CALL(mockUdpReader_1, createCommandListFromPacket(
        ::testing::_, _))
        .WillOnce(::testing::DoAll(
            ::testing::WithArgs<0>(::testing::SaveArg<0>(&captured_packet)), //Capture argument 0
            Return()
        ));
    //Motors1
    EXPECT_CALL(mockMotors_1, applyMotorsCommands(_)).Times(1); 

    //test
    Udp1::handleUdpPcks();

    //check
    if (captured_packet != nullptr) {
        std::copy(captured_packet, captured_packet + PACKET_SIZE, actual);
    }
    EXPECT_EQ(memcmp(actual, expected, PACKET_SIZE), 0);
}

int main(int argc, char **argv) {
    SetUpMocks();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
