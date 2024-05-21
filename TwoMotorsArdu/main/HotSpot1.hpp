#ifndef HOTSPOT1_HPP
#define HOTSPOT1_HPP

#include <ESP8266WebServer.h> //to start http server as hotspot config server
#include "WifiConn1.hpp"
#include "setPass.hpp"

const char *ssid = "Azucarito"; // Nombre del Hotspot
const char *password = "********"; // Contraseña del Hotspot
ESP8266WebServer server(80);

class HotSpot1 {
    public:
        static void start();
        static void handleReqs();
    private:
        static void handleRoot();
        static void handleConfig();
};

#endif
