#include "app_data.h"

void setup() {
  Serial.begin(115200);
  // displayOled.init(); // Inicializando la pantalla OLED
  // wifiConnection.init(); // Inicializando la conexion WiFi
  // displayOled.clearScreen();
  magneticModules.init();
  servos.init();
  delay(5000);
}

void loop() {
  servos.abrirEntrada();
  servos.cerrarEntrada();
  servos.abrirSalida();
  servos.cerrarSalida();
  magneticModules.verifyState();
  // displayOled.clearScreen();
  // displayOled.print("Leyendo sensores");
  delay(1000);
}
