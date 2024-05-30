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

bool carStatesG[] = {
  stateCar1,
  stateCar2
};

bool previousCarStatesG[] = {
  stateCar1,
  stateCar2
};

#define SENSOR_LUGAR_DISCAPACITADO_1 32  // GPIO 25

bool stateCarD1 = false;

bool carStatesD[] = {
  stateCarD1
};

bool previousCarStatesD[] = {
  stateCarD1
};

int lugaresDiscapacitados[] = {
  SENSOR_LUGAR_DISCAPACITADO_1
};

int availableGeneralPlaces = 0;
int availableDisabilitiePlaces = 0;

class MagneticModules {
public:
  void init(void);
  bool verifyGeneralPlacesState(void);
  int lengthLugaresGenerales(void);
  int lengthLugaresDiscapacitados(void);
  int updateAvailableGeneralPlaces(void);
  int updateAvailableDisabilitiesPlaces(void);
};

int MagneticModules::lengthLugaresGenerales(void) {
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

bool MagneticModules::verifyGeneralPlacesState(void) {
  bool stateChanged = false;

  for (int i = 0; i < lengthLugaresGenerales(); i++) {
    bool currentState = (digitalRead(lugaresDisponibles[i]) == HIGH);
    if (currentState != carStatesG[i]) {
      carStatesG[i] = currentState;
      stateChanged = true;
    }

    if (carStatesG[i]) {
      leds.turn_green(ledsGenerales[i][0], ledsGenerales[i][1]);  // Enciende el LED verde
      Serial.println("SENSOR_LUGAR_DISPONIBLE[" + String(i) + "] libre");
    } else {
      leds.turn_red(ledsGenerales[i][0], ledsGenerales[i][1]);  // Enciende el LED rojo
      Serial.println("SENSOR_LUGAR_DISPONIBLE[" + String(i) + "] ocupado");
    }
  }

  for (int i = 0; i < lengthLugaresDiscapacitados(); i++) {
    bool currentState = (digitalRead(lugaresDiscapacitados[i]) == HIGH);
    if (currentState != carStatesD[i]) {
      carStatesD[i] = currentState;
      stateChanged = true;
    }

    if (carStatesD[i]) {
      leds.turn_blue(ledsDiscapacitados[i][0], ledsDiscapacitados[i][1]);  // Enciende el LED azul
      Serial.println("SENSOR_LUGAR_DISCAPACITADO[" + String(i) + "] libre");
    } else {
      leds.turn_red(ledsDiscapacitados[i][0], ledsDiscapacitados[i][1]);  // Enciende el LED rojo
      Serial.println("SENSOR_LUGAR_DISCAPACITADO[" + String(i) + "] ocupado");
    }
  }

  return stateChanged;
}

int MagneticModules::updateAvailableGeneralPlaces(void) {  
  int occupiedGeneralPlaces = lengthLugaresGenerales();
  for (int i = 0; i < lengthLugaresGenerales(); i++) {
    if (carStatesG[i]) {
      occupiedGeneralPlaces--;
    }
  }

  availableGeneralPlaces = lengthLugaresGenerales() - occupiedGeneralPlaces;

  return availableGeneralPlaces;
}

int MagneticModules::updateAvailableDisabilitiesPlaces(void) {  
  int occupiedDisabilitiePlaces = lengthLugaresDiscapacitados();
  for (int i = 0; i < lengthLugaresDiscapacitados(); i++) {
    if (carStatesD[i]) {
      occupiedDisabilitiePlaces--;
    }
  }

  availableDisabilitiePlaces = lengthLugaresDiscapacitados() - occupiedDisabilitiePlaces;

  return availableDisabilitiePlaces;
}

#endif
