#include "HotSpot1.hpp"
#include "Motors1.hpp"
#include "Udp1.hpp"

void setup() {
  Serial.begin(115200);
  motors1.setup();
  HotSpot1::start();
  Serial.println("Hotspot iniciado. Conéctate a la red WiFi y visita la dirección IP 192.168.4.1 para configurar la red WiFi doméstica.");
}

void loop() {  
  if(WifiConn1::isConnected()){
    Udp1::handleUdpPcks();
  }
  else{
    HotSpot1::handleReqs();
  }
}
