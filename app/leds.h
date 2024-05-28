
#define LED1_GENERAL_R 25  // GPIO 25
#define LED1_GENERAL_G 26  // GPIO 26
#define LED2_GENERAL_R 27  // GPIO 27
#define LED2_GENERAL_G 14  // GPIO 14
#define LED1_DISCAPACITADOS_R 12  // GPIO 25
#define LED1_DISCAPACITADOS_B 15  // GPIO 26

int ledsGenerales[][2] = {
  { LED1_GENERAL_R, LED1_GENERAL_G },
  { LED2_GENERAL_R, LED2_GENERAL_G }
};

int ledsDiscapacitados[][2] = {
  { LED1_DISCAPACITADOS_R, LED1_DISCAPACITADOS_B }
};

class Leds {
public:
  void turn_blue(int led1, int led2);
  void turn_red(int led1, int led2);
  void turn_green(int led1, int led2);
  void init(void);
};

void Leds::init(void) {
  pinMode(LED1_GENERAL_R, OUTPUT);
  pinMode(LED1_GENERAL_G, OUTPUT);
  pinMode(LED2_GENERAL_R, OUTPUT);
  pinMode(LED2_GENERAL_G, OUTPUT);
  pinMode(LED1_DISCAPACITADOS_B, OUTPUT);
  pinMode(LED1_DISCAPACITADOS_R, OUTPUT);
}

void Leds::turn_red(int led1, int led2) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
}

void Leds::turn_green(int led1, int led2) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}

void Leds::turn_blue(int led1, int led2) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}
