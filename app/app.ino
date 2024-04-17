#include "data.h"

void setup() {
  Serial.begin(115200);
  displayOled.init();    // Inicializando la pantalla OLED
  wifiConnection.init(); // Inicializando la conexion WiFi

  delay(5000);
  displayOled.clearScreen();
}

void loop() {}