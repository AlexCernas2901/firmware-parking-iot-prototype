#include "app_data.h"

// long lastMsg = 0;

void setup(void) {
  Serial.begin(115200);

  mqtt.setup_WiFi ( );
  mqtt.set_MQTT_server ( );
  mqtt.set_MQTT_callback (  );
  
  displayOled.init(); // Inicializando la pantalla OLED
  tsk.tareaOLED();
  microSD.init(); // Inicializando la MicroSD
  magneticModules.init();
  servos.init(); //
  leds.init(); //Inicializando los leds
  myRTC.init(); // Inicializando el RTC
}

void loop(void) {
  tsk.actualizarTareas();

  tsk.tareaAbrirEntrada();
  tsk.tareaCerrarEntrada();
  tsk.tareaAbrirSalida();
  tsk.tareaCerrarSalida();

  tsk.tareaVerifyPlaces();

  Serial.println(String(magneticModules.verifyGeneralPlacesState()));
  if (magneticModules.verifyGeneralPlacesState()) {
    tsk.tareaMQTT();
  }

  tsk.tareaOLED();
  // displayOled.clearScreen();
  // displayOled.print("Leyendo sensores");

/*  mqtt.reconnect_MQTT ( );

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;  
    mqtt.publish_MQTT ( );
  } */

  // tsk.tareaMicroSD();
  tsk.tareaMicroSD();
  delay(1000);
}
