#include "app_data.h"

void setup() {
  Serial.begin(115200);
  // displayOled.init(); // Inicializando la pantalla OLED
  // wifiConnection.init(); // Inicializando la conexion WiFi
  // displayOled.clearScreen();
  MSD.MicroSD_init(); // Inicializando la MicroSD
  magneticModules.init();
  servos.init();
  delay(5000);
  myrtc.RTC_init(); // Inicializando el RTC
}

void loop() {
  servos.abrirEntrada();
  servos.cerrarEntrada();
  servos.abrirSalida();
  servos.cerrarSalida();
  magneticModules.verifyState();
  // displayOled.clearScreen();
  // displayOled.print("Leyendo sensores");
  myrtc.get_time(); // Obteniendo la fecha y hora del RTC
  myrtc.show_time(); // Mostrando la fecha y hora en la consola serial
  delay(1000);
  TSK.actualizar_tareas();
  TSK.tarea_MSD();

}
