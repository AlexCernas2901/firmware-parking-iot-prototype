#include "wifi.h"
#include "displayOled.h"
#include "rfid.h"

WIFI_CONNECTION wifi;  // Instanciando la clase WIFI_CONNECTION
DISPLAY_OLED oled;     // Instanciado la clase DISPLAY_OLED
RFID rfid;             // Instanciando la clase RFID

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
