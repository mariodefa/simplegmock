#ifndef HOTSPOT1_HPP
#define HOTSPOT1_HPP

#include <WebServer.h> //to start http server as hotspot config server
#include "WifiConn1.hpp"
#include "setPass.hpp"

const String SSID1 = "Azucarito"; // Nombre del Hotspot
const String PASSWORD = "********"; // Contraseña del Hotspot

class HotSpot1 {
    public:
        static void start1();
        static void handleReqs();
    private:
        static void handleRoot();
        static void handleConfig();
};

#endif
