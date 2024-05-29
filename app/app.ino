#include "app_data.h"

long lastMsg = 0;

void setup(void) {
  Serial.begin(115200);
  mqtt.setup_WiFi ( );
  mqtt.set_MQTT_server ( );
  mqtt.set_MQTT_callback (  );
  
  displayOled.init(); // Inicializando la pantalla OLED
  // displayOled.clearScreen();
  // microSD.init(); // Inicializando la MicroSD
  magneticModules.init();
  servos.init(); //
  leds.init(); //Inicializando los leds
  myRTC.init(); // Inicializando el RTC
}

void loop(void) {
  displayOled.clearScreen();
  tsk.actualizarTareas();

  tsk.tareaAbrirEntrada();
  tsk.tareaCerrarEntrada();
  tsk.tareaAbrirSalida();
  tsk.tareaCerrarSalida();

  tsk.tareaVerifyPlaces();
  // tsk.tareaOLED();

  json.data();

  // displayOled.clearScreen();
  // displayOled.print("Leyendo sensores");

  mqtt.reconnect_MQTT ( );

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;  
    mqtt.publish_MQTT ( );
  }

  displayOled.printMessage(String(magneticModules.updateAvailableGeneralPlaces()), 0, 32);
  displayOled.printMessage(String(magneticModules.updateAvailableDisabilitiesPlaces()), 0, 40);
  displayOled.clearScreen();
  // tsk.tareaMicroSD();
}
