#include "wifi.h"
#include "displayOled.h"
#include "rfid.h"

WifiConnection wifi;  // Instanciando la clase WifiConnection
DisplayOled oled;     // Instanciando la clase DisplayOled
Rfid rfid;            // Instanciando la clase Rfid

void setup() {
  Serial.begin(115200);
  oled.display_initialization();  // Inicializando la pantalla OLED
  wifi.stablish_connection();     // Inicializando la conexion WiFi
  oled.display_print_message(wifi.get_connection_status(), 0, 0);
  rfid.rfid_initialization();

  delay(5000);
  oled.display_clear_screen();
}

void loop() {
}
