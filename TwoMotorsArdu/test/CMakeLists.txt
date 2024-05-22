# previous working link https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# UdpReader1Test Lib
# dependent on:
#    Command1
#    UdpReader1
add_executable(UdpReader1Test
  UdpReader1Test.cpp
)
target_link_libraries(UdpReader1Test
  PRIVATE
    Command1
    UdpReader1
    GTest::gtest_main
)

# Udp1Test Lib
# dependent on:
#    Udp1
#    Gmock
add_executable(Udp1Test
  Udp1Test.cpp
)
target_link_libraries(Udp1Test
  PRIVATE
    Udp1
    GTest::gtest_main
    GTest::gmock_main
)

# Udp1IntegrationTest Lib
# dependent on:
#    Udp1
#    UdpReader1
#    Gmock
add_executable(Udp1IntegrationTest
  Udp1IntegrationTest.cpp
)
target_link_libraries(Udp1IntegrationTest
  PRIVATE
    Udp1
    UdpReader1
    GTest::gtest_main
    GTest::gmock_main
)

include(GoogleTest)
# test libs list
gtest_discover_tests(UdpReader1Test)
gtest_discover_tests(Udp1Test)
gtest_discover_tests(Udp1IntegrationTest)
