#include "data.h"

void setup() {
  Serial.begin(115200);
  // displayOled.init();    // Inicializando la pantalla OLED
  // wifiConnection.init(); // Inicializando la conexion WiFi
  // displayOled.clearScreen();
  // magneticModules.init();
  MSD.MicroSD_init();
  delay(5000);
}

void loop() {
  // displayOled.clearScreen();
  // displayOled.print("Leyendo sensores", 0, 0);
  delay(1000);
  TSK.actualizar_tareas();
  TSK.tarea_MSD();

}
