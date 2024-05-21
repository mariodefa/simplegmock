#include "HotSpot1.hpp"

void HotSpot1::start() {
    WiFi.softAP(ssid, password);    
    server.on("/", HTTP_GET, handleRoot);
    server.on("/config", HTTP_GET, handleConfig);
    server.begin();
}

void HotSpot1::handleReqs(){
    server.handleClient();
}

//PRIVATE 

void HotSpot1::handleRoot() {
    server.send(200, "text/html", setPassPage);
}

void HotSpot1::handleConfig() {
    String wifiName = server.arg(wifiNameId);
    String wifiPass = server.arg(wifiPassId);
    server.stop();
    WifiConn1::connectToDomesticWifi(wifiName, wifiPass);
}
