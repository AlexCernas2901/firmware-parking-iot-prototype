#ifndef MAGNETIC_MODULES_H
#define MAGNETIC_MODULES_H

#define SENSOR_ENTRADA_1 16  // GPIO 16
#define SENSOR_ENTRADA_2 4   // GPIO 4

#define SENSOR_SALIDA_1 34  // GPIO 34
#define SENSOR_SALIDA_2 39  // GPIO 39

#define SENSOR_LUGAR_DISPONIBLE_1 36  // GPIO 36
#define SENSOR_LUGAR_DISPONIBLE_2 35  // GPIO 35

int lugaresDisponibles[] = {
  SENSOR_LUGAR_DISPONIBLE_1,
  SENSOR_LUGAR_DISPONIBLE_2
};

bool stateCar1 = false;
bool stateCar2 = false;

bool carStates[] = {
  stateCar1,
  stateCar2
};

#define SENSOR_LUGAR_DISCAPACITADO_1 32  // GPIO 25

bool stateCarD1 = false;

bool carStatesD[] = {
  stateCarD1,
};

int lugaresDiscapacitados[] = {
  SENSOR_LUGAR_DISCAPACITADO_1
};

class MagneticModules {
public:
  void init(void);
  void verifyGeneralState(void);
  int lengthLugaresDisponibles(void);
  int lengthLugaresDiscapacitados(void);
};

int MagneticModules::lengthLugaresDisponibles(void) {
  return sizeof(lugaresDisponibles) / sizeof(lugaresDisponibles[0]);
}

int MagneticModules::lengthLugaresDiscapacitados(void) {
  return sizeof(lugaresDiscapacitados) / sizeof(lugaresDiscapacitados[0]);
}

void MagneticModules::init(void) {
  pinMode(SENSOR_ENTRADA_1, INPUT);
  pinMode(SENSOR_ENTRADA_2, INPUT);

  pinMode(SENSOR_SALIDA_1, INPUT);
  pinMode(SENSOR_SALIDA_2, INPUT);

  pinMode(SENSOR_LUGAR_DISPONIBLE_1, INPUT);
  pinMode(SENSOR_LUGAR_DISPONIBLE_2, INPUT);

  pinMode(SENSOR_LUGAR_DISCAPACITADO_1, INPUT);
}

void MagneticModules::verifyGeneralState(void) {
  for (int i = 0; i < lengthLugaresDisponibles(); i++) {
    if (digitalRead(lugaresDisponibles[i]) == LOW) {
      Serial.println("SENSOR_LUGAR_DISPONIBLE[" + String(i) + "] ocupado");
      leds.turn_red(ledsGenerales[i][0], ledsGenerales[i][1]);  // Enciende el LED rojo
      carStates[i] = false;
      delay(1000);
    } else {
      Serial.println("SENSOR_LUGAR_DISPONIBLE[" + String(i) + "] libre");
      leds.turn_green(ledsGenerales[i][0], ledsGenerales[i][1]);  // Enciende el LED rojo
      carStates[i] = true;
      delay(1000);
    }
  }

  for (int i = 0; i < lengthLugaresDiscapacitados(); i++) {
    if (digitalRead(lugaresDiscapacitados[i]) == LOW) {
      Serial.println("SENSOR_LUGAR_DISCAPACITADO[" + String(i) + "] ocupado");
      leds.turn_red(ledsDiscapacitados[i][0], ledsDiscapacitados[i][1]);  // Enciende el LED rojo
      carStatesD[i] = false;
      delay(1000);
    } else {
      Serial.println("SENSOR_LUGAR_DISCAPACITADO[" + String(i) + "] libre");
      leds.turn_blue(ledsDiscapacitados[i][0], ledsDiscapacitados[i][1]);  // Enciende el LED azul
      carStatesD[i] = true;
      delay(1000);
    }
  }
}

#endif
