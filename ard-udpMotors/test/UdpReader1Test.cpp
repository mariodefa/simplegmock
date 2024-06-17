#include "gtest/gtest.h"
#include "UdpReader1.hpp"
#include "Command1.hpp"

UdpReader1 udpReader1_1 = UdpReader1();

class UdpReader1Test : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(UdpReader1Test, CreateCommandListFromPacketTest) {
    //fixtures
    //255 = '\xFF', 100 = 'd', 127 = '\x7F', 90 = '\x5A', 180 = '\xB4'
    char packet[PACKET_SIZE] = {'\xFF', 'b', 'd', 'f', '\0', 'f', '\x7F', 'f', '\x5A', 'f', '\xB4', 'f'};

    //EXPECTED
    Command1 expected[N_COMMANDS] = {Command1(), Command1(), Command1(), Command1()};
    expected[0] = Command1(255,Direction::backward);
    expected[1] = Command1(100,Direction::forward);
    expected[2] = Command1(0,Direction::forward);
    expected[3] = Command1(127,Direction::forward);
    expected[4] = Command1(90,Direction::forward);//servo1
    expected[5] = Command1(180,Direction::forward);//servo2

    //test
    Command1 actual[N_COMMANDS];
    udpReader1_1.createCommandListFromPacket(packet, actual);

    //check
    for (int i = 0; i < N_COMMANDS; ++i) {
        EXPECT_EQ(actual[i].getPwm(), expected[i].getPwm());
        EXPECT_EQ(actual[i].getDirection(), expected[i].getDirection());
    }
}

TEST_F(UdpReader1Test, CreateCommandFromChunkTest) {
    //fixtures
    //255 = '\xFF'
    unsigned char chunk[CHUNK_SIZE] = {0xFF, 'b'};

    //EXPECTED
    Command1 expected = Command1(255,Direction::backward);

    //test
    Command1 actual = udpReader1_1.createCommandFromChunk(chunk);

    //check
    EXPECT_EQ(actual.getPwm(), expected.getPwm());
    EXPECT_EQ(actual.getDirection(), expected.getDirection());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
