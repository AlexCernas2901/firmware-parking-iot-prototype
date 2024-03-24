#include <SD.h>
#include <SPI.h>

File MicroSD_File;  // Archivo para escribir  o leer en la MicroSD

class MicroSD {
  // Variables
public:
  uint8_t contador = 0;
  String filename = "/TestMicroSD.txt";  // Nombre de archivo que incluye "/" que indica la ubicación en raíz

  // Metodos
public:
  void MicroSD_init(void);
  void SaveFile(void);
  void ReadFile(void);
};

void MicroSD::MicroSD_init(void) {
  while (!SD.begin(MICROSD_PIN)) {
    Serial.println(F("Falló la inicialización del módulo MicroSD"));
    delay(1000);
  }
  Serial.println(F("La librería MicroSD ha inicializado con éxito"));
}

void MicroSD::SaveFile(void) {
  MicroSD_File = SD.open(filename, FILE_APPEND);

  if (MicroSD_File) {
    MicroSD_File.print(F("Contador en: "));
    MicroSD_File.println(contador);
    contador++;
    MicroSD_File.close();
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
  MicroSD_File = SD.open(filename);

  if (MicroSD_File) {
    Serial.println("Archivo:");

    while (MicroSD_File.available()) {
      Serial.write(MicroSD_File.read());
    }

    MicroSD_File.close();
  } else {
    Serial.println("Error abriendo el archivo");
  }
}
