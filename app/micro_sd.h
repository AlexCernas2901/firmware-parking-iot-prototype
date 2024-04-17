#include <SD.h>
#include <SPI.h>

File microSDFile; // Archivo para escribir  o leer en la MicroSD

class MicroSD {
public:
  uint8_t contador = 0;
  String filename = "/test_microsd.txt"; // Nombre de archivo que incluye "/" que indica la ubicación en raíz

public:
  void init(void);
  void saveFile(void);
  void readFile(void);
};

void MicroSD::init(void) {
  while (!SD.begin(MICROSD_PIN)) {
    Serial.println(F("Falló la inicialización del módulo MicroSD"));
    delay(1000);
  }
  Serial.println(F("La librería MicroSD ha inicializado con éxito"));
}

void MicroSD::saveFile(void) {
  microSDFile = SD.open(filename, FILE_APPEND);

  if (microSDFile) {
    microSDFile.print(F("Contador en: "));
    microSDFile.println(contador);
    contador++;
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

void MicroSD::readFile(void) {
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