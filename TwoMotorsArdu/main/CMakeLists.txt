add_library(UdpReader1)

target_sources(UdpReader1
  PRIVATE
    Command1.cpp
    UdpReader1.cpp
  PUBLIC
    Command1.hpp
    UdpReaderInterface.hpp
    UdpReader1.hpp
  )

target_include_directories(UdpReader1
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )