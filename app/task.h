#ifndef Tasks_h
#define Tasks_h

#define TIEMPO_MSD 10000

class millis_tasks {

  public:
    uint64_t tiempo_anterior_MSD = 0,  // Contador de tiempo que tendrá múltiplos de TIEMPO3.
             tiempo_actual = 0;      // Contador de tiempo que tendrá múltiplos de TIEMPO.
    
  public:

    void tarea_MSD ( void );
    void actualizar_tareas (void );  // Función que actualiza el conteo obtenido de la función "millis()".
 
};

void millis_tasks :: tarea_MSD ( void ) {
  if ( ( tiempo_actual - tiempo_anterior_MSD ) >= TIEMPO_MSD ){
    myrtc.get_time();

    String filename = myrtc.format_date('/') + " " + myrtc.format_time();
    MSD.saveFile(filename);
    MSD.readFile();
    
     Serial.println ( "Ejecutando tarea MSD" );
     tiempo_anterior_MSD = tiempo_actual;
  }
}




void millis_tasks :: actualizar_tareas ( void ) {
  tiempo_actual = millis( );
}

#endif
