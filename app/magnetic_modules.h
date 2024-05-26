#ifndef MAGNETIC_MODULES_H
#define MAGNETIC_MODULES_H


#define SENSOR_ENTRADA_1 16 // GPIO 16
#define SENSOR_ENTRADA_2 4  // GPIO 4

#define SENSOR_SALIDA_1 34 // GPIO 34
#define SENSOR_SALIDA_2 39 // GPIO 39

#define SENSOR_LUGAR_DISPONIBLE_1 36 // GPIO 36
#define SENSOR_LUGAR_DISPONIBLE_2 35 // GPIO 35
#define SENSOR_LUGAR_DISPONIBLE_3 32 // GPIO 32

int lugaresDisponibles[] = {
  SENSOR_LUGAR_DISPONIBLE_1,
  SENSOR_LUGAR_DISPONIBLE_2,
  SENSOR_LUGAR_DISPONIBLE_3
};

#define SENSOR_LUGAR_DISCAPACITADO_1 25 // GPIO 25

int lugaresDiscapacitados[] = {
  SENSOR_LUGAR_DISCAPACITADO_1
};

class MagneticModules {
public:
  void init(void);
  void verifyState(void);
};

void MagneticModules::init(void) {
  pinMode(SENSOR_ENTRADA_1, INPUT);
  pinMode(SENSOR_ENTRADA_2, INPUT);

  pinMode(SENSOR_SALIDA_1, INPUT);
  pinMode(SENSOR_SALIDA_2, INPUT);

  pinMode(SENSOR_LUGAR_DISPONIBLE_1, INPUT);
  pinMode(SENSOR_LUGAR_DISPONIBLE_2, INPUT);
  pinMode(SENSOR_LUGAR_DISPONIBLE_3, INPUT);

  pinMode(SENSOR_LUGAR_DISCAPACITADO_1, INPUT);
}

void MagneticModules::verifyState(void) {
  if (digitalRead(SENSOR_LUGAR_DISPONIBLE_1) == LOW) {
    Serial.println("SENSOR_LUGAR_DISPONIBLE_1 activado");
  }
  if (digitalRead(SENSOR_LUGAR_DISPONIBLE_2) == LOW) {
    Serial.println("SENSOR_LUGAR_DISPONIBLE_2 activado");
  }
  if (digitalRead(SENSOR_LUGAR_DISPONIBLE_3) == LOW) {
    Serial.println("SENSOR_LUGAR_DISPONIBLE_3 activado");
  }
  if (digitalRead(SENSOR_LUGAR_DISCAPACITADO_1) == LOW) {
    Serial.println("SENSOR_LUGAR_DISCAPACITADO_1 activado");
  }
}

#endif
