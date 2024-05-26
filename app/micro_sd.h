#ifndef MicroSD_h
#define MicroSD_h


#include <SD.h>
#include <SPI.h>
#define MICROSD_PIN 5
File microSDFile; // Archivo para escribir  o leer en la MicroSD

class MicroSD {
public:
  
  String filename = "/registro_microsd.txt"; // Nombre de archivo que incluye "/" que indica la ubicación en raíz

public:
  void MicroSD_init(void);
  void SaveFile(String);
  void ReadFile(void);
};

void MicroSD::MicroSD_init ( void ){

   while ( !SD.begin ( MICROSD_PIN ) ) {
        Serial.println ( F ( "Falló la inicialización del módulo MicroSD"  ));
        delay(1000);
    }
            delay(1000);

    Serial.println ( F ( "La librería MicroSD ha inicializado con éxito" ) );
}

void MicroSD::SaveFile(String msg) {
    //MYRTC.get_time();
    //MYRTC.format_date('_');
    //filename = "/";
    //filename += MYRTC.format_date('_');
  microSDFile = SD.open(filename, FILE_APPEND);

  if (microSDFile) {
    
    microSDFile.println(msg);
    
    microSDFile.close();
  } else {
    Serial.print(F("Error opening "));
    Serial.println(filename);
  }

  Serial.println("Verificando si existe el archivo: ");

  if (SD.exists(filename)) {
    Serial.println(filename);
    Serial.println(" existe");
  } else {
    Serial.println(filename);
    Serial.println(" no existe");
  }

  delay(1000);
}

void MicroSD::ReadFile(void) {
  microSDFile = SD.open(filename);

  if (microSDFile) {
    Serial.println("Archivo:");

    while (microSDFile.available()) {
      Serial.write(microSDFile.read());
    }

    microSDFile.close();
  } else {
    Serial.println("Error abriendo el archivo");
  }
}

#endif
