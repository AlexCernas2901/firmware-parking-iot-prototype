#ifndef Tasks_h
#define Tasks_h

#define TIEMPO_MICRO_SD 1000
#define TIEMPO_ABRIR_ENTRADA 1000
#define TIEMPO_CERRAR_ENTRADA 100
#define TIEMPO_ABRIR_SALIDA 100
#define TIEMPO_CERRAR_SALIDA 100
#define TIEMPO_VERIFY_GENERAL_PLACES_STATE 200
#define TIEMPO_OLED 200 
#define TIEMPO_MQTT 200

class millis_tasks {

  public:
    uint64_t tiempoActual = 0,      // Contador de tiempo que tendrá múltiplos de TIEMPO.
             tiempoAnteriorMicroSD = 0,  // Contador de tiempo que tendrá múltiplos de TIEMPO3.
             tiempoAnteriorAbrirEntrada = 0,
             tiempoAnteriorCerrarEntrada = 0,
             tiempoAnteriorAbrirSalida = 0,
             tiempoAnteriorCerrarSalida = 0,
             tiempoAnteriorVerifyGeneralPlacesState = 0,
             tiempoAnteriorOLED = 0,
             tiempoAnteriorMQTT = 0;
  public:
    void actualizarTareas (void );  // Función que actualiza el conteo obtenido de la función "millis()".
    void tareaMicroSD ( void );
    void tareaAbrirEntrada(void);
    void tareaCerrarEntrada(void);
    void tareaAbrirSalida(void);
    void tareaCerrarSalida(void);
    void tareaVerifyPlaces(void);
    void tareaOLED(void);
    void tareaMQTT(void);
};

void millis_tasks :: tareaMicroSD ( void ) {
  if ( ( tiempoActual - tiempoAnteriorMicroSD ) >= TIEMPO_MICRO_SD ){
    String cars = json.data() + ",";

    microSD.saveFile(cars);
    microSD.readFile();
    
    Serial.println ( "Ejecutando tarea MicroSD" );
    tiempoAnteriorMicroSD = tiempoActual;
  }
}

void millis_tasks :: tareaAbrirEntrada ( void ) {
  if ( ( tiempoActual - tiempoAnteriorAbrirEntrada ) >= TIEMPO_ABRIR_ENTRADA ){
    servos.abrirEntrada();

    Serial.println ( "Ejecutando tarea abrirEntrada" );
    tiempoAnteriorAbrirEntrada = tiempoActual;
  }
}

void millis_tasks :: tareaCerrarEntrada ( void ) {
  if ( ( tiempoActual - tiempoAnteriorCerrarEntrada ) >= TIEMPO_CERRAR_ENTRADA ){
    servos.cerrarEntrada();

    Serial.println ( "Ejecutando tarea cerrarEntrada" );
    tiempoAnteriorCerrarEntrada = tiempoActual;
  }
}

void millis_tasks :: tareaAbrirSalida ( void ) {
  if ( ( tiempoActual - tiempoAnteriorAbrirSalida ) >= TIEMPO_ABRIR_SALIDA ){
    servos.abrirSalida();

    Serial.println ( "Ejecutando tarea abrirSalida" );
    tiempoAnteriorAbrirSalida = tiempoActual;
  }
}

void millis_tasks :: tareaCerrarSalida ( void ) {
  if ( ( tiempoActual - tiempoAnteriorCerrarSalida ) >= TIEMPO_CERRAR_SALIDA ){
    servos.cerrarSalida();

    Serial.println ( "Ejecutando tarea cerrarSalida" );
    tiempoAnteriorCerrarSalida = tiempoActual;
  }
}

void millis_tasks :: tareaVerifyPlaces ( void ) {
  if ( ( tiempoActual - tiempoAnteriorVerifyGeneralPlacesState ) >= TIEMPO_VERIFY_GENERAL_PLACES_STATE ){
    magneticModules.verifyGeneralPlacesState();

    Serial.println ( "Ejecutando tarea cerrarSalida" );
    tiempoAnteriorVerifyGeneralPlacesState = tiempoActual;
  }
}

void millis_tasks ::  tareaOLED ( void ) {
  if ( ( tiempoActual - tiempoAnteriorOLED ) >= TIEMPO_OLED ){
  displayOled.printMessage("Generales:" + String(magneticModules.updateAvailableGeneralPlaces()), "Discapacitados:" + String(magneticModules.updateAvailableDisabilitiesPlaces()));

    Serial.println ( "Ejecutando tarea displayOled" );
    tiempoAnteriorOLED = tiempoActual;
  }
}

void millis_tasks :: tareaMQTT(void) {
  if ( ( tiempoActual - tiempoAnteriorMQTT ) >= TIEMPO_MQTT ){
    long lastMsg = 0;

    mqtt.reconnect_MQTT ( );

    long now = millis();
    if (now - lastMsg > 5000) {
      lastMsg = now;  
      mqtt.publish_MQTT ( );
    }

    Serial.println ( "Ejecutando tarea publish_MQTT" );
    tiempoAnteriorMQTT = tiempoActual;
  }
}

void millis_tasks :: actualizarTareas ( void ) {
  tiempoActual = millis( );
}

#endif
