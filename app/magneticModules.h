class magneticModules {
public:
  const int8_t SENSOR_1 = 23;
  const int8_t SENSOR_2 = 22;
  const int8_t SENSOR_3 = 21;
  const int8_t SENSOR_4 = 20;
  const int8_t SENSOR_ENTRADA_1 = 27;
  const int8_t SENSOR_ENTRADA_2 = 26;
  const int8_t SENSOR_SALIDA_1 = 25;
  const int8_t SENSOR_SALIDA_2 = 24;

public:
  void sensor_init(void);
  void sensor_count(void);
  void sensor_state();
}