#include "wifi.h"
#include "displayOled.h"

WIFI_CONNECTION wifi;  // Instanciando la clase WIFI_CONNECTION
DISPLAY_OLED oled;     // Instanciado la clase DISPLAY_OLED

void setup() {
  Serial.begin(115200);
  oled.display_initialization();  // Inicializando la conexion WiFi
  wifi.stablish_connection();     // Inicializando la conexion WiFix
  oled.display_print_message(wifi.get_connection_status());
  delay(5000);
  oled.display_clear_screen();
}

void loop() {
}
