#ifndef SETPASS_HPP
#define SETPASS_HPP
//this is the landing web page of the hotspot

String setPassPage = "<html><body><h1>Configurar Red WiFi</h1><form action='/config' method='get'>SSID: <input type='text' name='ssid'><br>Contraseña: <input type='password' name='password'><br><input type='submit' value='Enviar'></form></body></html>";
String wifiNameId = "ssid";
String wifiPassId = "password";

#endif
