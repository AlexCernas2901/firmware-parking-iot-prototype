class magneticModules {
public:
  const int8_t SENSOR_1 = 0;
  const int8_t SENSOR_2 = 0;
  const int8_t SENSOR_3 = 0;
  const int8_t SENSOR_4 = 0;
  const int8_t SENSOR_ENTRADA_1 = 0;
  const int8_t SENSOR_ENTRADA_2 = 0;
  const int8_t SENSOR_SALIDA_1 = 0;
  const int8_t SENSOR_SALIDA_2 = 0;

public:
  void sensor_init(void);
  void sensor_count(void);
  void sensor_state();
}