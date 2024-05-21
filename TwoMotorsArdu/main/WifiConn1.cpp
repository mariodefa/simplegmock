#include "WifiConn1.hpp"

bool WifiConn1::connected = false;

void WifiConn1::connectToDomesticWifi(String wifiName, String wifiPass) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifiName.c_str(), wifiPass.c_str());
    int timeout = 0;
    while (WiFi.status() != WL_CONNECTED && timeout < 5000) {
        delay(500);
        Serial.print(".");
        timeout += 500;
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("Conexión exitosa a la red WiFi doméstica.");
        Serial.println("Dirección IP: ");
        Serial.println(WiFi.localIP());
        connected = true;
        Udp1::linkDependencies(udpReader1,motors1);
        Udp1::startUdpSocket(wiFiUDPReal,serialReal);
    } else {
        Serial.println("");
        Serial.println("Error al conectar a la red WiFi doméstica.");
    }
}

bool WifiConn1::isConnected(){
    return connected;
}