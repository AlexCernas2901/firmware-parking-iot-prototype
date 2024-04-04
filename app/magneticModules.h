class MagneticModules {
  // Variables
public:
  const int8_t SENSOR_1 = 23;          // GPIO 15
  const int8_t SENSOR_2 = 22;          // GPIO 8
  const int8_t SENSOR_3 = 21;          // GPIO 7
  const int8_t SENSOR_4 = 20;          // GPIO 6
  const int8_t SENSOR_ENTRADA_1 = 27;  // GPIO 16
  const int8_t SENSOR_ENTRADA_2 = 26;  // GPIO 4
  const int8_t SENSOR_SALIDA_1 = 25;   // GPIO 0
  const int8_t SENSOR_SALIDA_2 = 24;   // GPIO 2

  // Metodos
public:
  void sensor_init(void);
  void sensor_count(void);
  void sensor_state();
}