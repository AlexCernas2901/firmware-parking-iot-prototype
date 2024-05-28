#include "app_data.h"

void setup() {
  Serial.begin(115200);
  // displayOled.init(); // Inicializando la pantalla OLED
  // displayOled.clearScreen();
  // displayOled.printMessage("Hola");
  // wifiConnection.init(); // Inicializando la conexion WiFi
  MSD.init(); // Inicializando la MicroSD
  magneticModules.init();
  servos.init(); //
  leds.init(); //Inicializando los leds
  delay(5000);
  myrtc.init(); // Inicializando el RTC
}

void loop() {
  servos.abrirEntrada();
  servos.cerrarEntrada();
  servos.abrirSalida();
  servos.cerrarSalida();
  magneticModules.verifyGeneralState();
  json.cars_json();
  // displayOled.clearScreen();
  // displayOled.print("Leyendo sensores");
  myrtc.get_time(); // Obteniendo la fecha y hora del RTC
  myrtc.show_time(); // Mostrando la fecha y hora en la consola serial
  delay(1000);
  TSK.actualizar_tareas();
  TSK.tarea_MSD();
}
