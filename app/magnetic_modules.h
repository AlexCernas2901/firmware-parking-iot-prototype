class MagneticModules {
public:
  const int8_t SENSOR1 = 23;         // GPIO 15
  const int8_t SENSOR2 = 22;         // GPIO 8
  const int8_t SENSOR3 = 21;         // GPIO 7
  const int8_t SENSOR4 = 20;         // GPIO 6
  const int8_t SENSOR_ENTRADA1 = 27; // GPIO 16
  const int8_t SENSOR_ENTRADA2 = 26; // GPIO 4
  const int8_t SENSOR_SALIDA1 = 25;  // GPIO 0
  const int8_t SENSOR_SALIDA2 = 24;  // GPIO 2

public:
  void init(void);
  void sensorCount(void);
  void sensorState();
};