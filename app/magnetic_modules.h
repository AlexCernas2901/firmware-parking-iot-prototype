class MagneticModules {
public:
  const int8_t SENSOR_E1 = 27; // GPIO 16
  const int8_t SENSOR_E2 = 26; // GPIO 4
  const int8_t SENSOR_S1 = 25; // GPIO 0
  const int8_t SENSOR_S2 = 24; // GPIO 2

  static const int SENSORES_LUGARES_DISPONIBLES[3];
  static const int SENSORES_LUGARES_DISCAPACITADOS[1];

  const int LUGARES_DISPONIBLES;
  const int LUGARES_DISCAPACITADOS;

  const int LUGARES_TOTALES;

public:
  void init(void);
};

const int MagneticModules::LUGARES_DISPONIBLES = sizeof(MagneticModules::SENSORES_LUGARES_DISPONIBLES) / sizeof(MagneticModules::SENSORES_LUGARES_DISPONIBLES[0]);
const int MagneticModules::LUGARES_DISCAPACITADOS = sizeof(MagneticModules::SENSORES_LUGARES_DISCAPACITADOS) / sizeof(MagneticModules::SENSORES_LUGARES_DISCAPACITADOS[0]);

const int MagneticModules::LUGARES_TOTALES = MagneticModules::LUGARES_DISPONIBLES + MagneticModules::LUGARES_DISCAPACITADOS;

const int MagneticModules::SENSORES_LUGARES_DISPONIBLES[3] = {
  23, // GPIO 15
  22, // GPIO 8
  21, // GPIO 7
};

const int MagneticModules::SENSORES_LUGARES_DISCAPACITADOS[1] = {
  20, // GPIO 6
};

void MagneticModules::init(void) {
  pinMode(SENSOR_E1, INPUT);
  pinMode(SENSOR_E2, INPUT);
  pinMode(SENSOR_S1, INPUT);
  pinMode(SENSOR_S2, INPUT);

  for (int i = 0; i < LUGARES_DISPONIBLES; i++) {
    pinMode(SENSORES_LUGARES_DISPONIBLES[i], INPUT);
  }

  for (int i = 0; i < LUGARES_DISCAPACITADOS; i++) {
    pinMode(SENSORES_LUGARES_DISCAPACITADOS[i], INPUT);
  }
}
