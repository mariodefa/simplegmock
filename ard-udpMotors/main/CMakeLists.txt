# Command1 Lib
add_library(Command1
  Command1.cpp
)
target_include_directories(Command1
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
 
# UdpReader1 Lib
# dependent on:
#    Command1
add_library(UdpReader1 
  UdpReader1.cpp
)
target_link_libraries(UdpReader1
  Command1
)
target_include_directories(UdpReader1
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# Udp1 Lib
# dependent on:
#    Command1
#    UdpReader1
add_library(Udp1 
  Udp1.cpp
)
# WiFiUDPReal and SerialReal not included, not necessary for tests
# "Real" libs not intended for cmake building, only for arduino compiler
target_link_libraries(Udp1
  Command1
  UdpReader1
)
target_include_directories(Udp1
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)