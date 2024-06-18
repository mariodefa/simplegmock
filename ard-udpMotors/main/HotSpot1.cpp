#include "HotSpot1.hpp"

WebServer server(80);

void HotSpot1::start1() {
    WiFi.softAP(SSID1.c_str(), PASSWORD.c_str());    
    server.on("/", HTTP_GET, handleRoot);
    server.on("/config", HTTP_GET, handleConfig);
    server.begin();
}

void HotSpot1::handleReqs(){
    server.handleClient();
}

//PRIVATE 

void HotSpot1::handleRoot() {
    server.send(200, "text/html", SET_PASS_PAGE);
}

void HotSpot1::handleConfig() {
    String wifiName = server.arg(WIFI_NAME_ID);
    String wifiPass = server.arg(WIFI_PASS_ID);
    server.stop();
    WifiConn1::connectToDomesticWifi(wifiName, wifiPass);
}
