#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

class DISPLAY_OLED {
  // Variables
public:
  const uint8_t SCREEN_ADDRESS = 0x3C;
  const uint8_t SCREEN_WIDTH = 128;
  const uint8_t SCREEN_HEIGHT = 64;
  const uint8_t SCREEN_X = 0;
  const uint8_t SCREEN_Y = 0;
  const int8_t OLED_RESET = -1;
  Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  // Metodos
public:
  void display_initialization(void);
  void display_print_message(String message, uint8_t SCREEN_X, uint8_t SCREEN_Y);
  void display_clear_screen(void);
};

void DISPLAY_OLED::display_initialization(void) {
  delay(250);       // Esperando a que el OLED se encienda
  display.begin();  // Inicializando la comunicación con la pantalla
}

void DISPLAY_OLED::display_print_message(String message, uint8_t SCREEN_X, uint8_t SCREEN_Y) {
  display.clearDisplay();                 // Limpiando la pantalla
  display.setTextSize(1);                 // Estableciendo el tamaño del texto
  display.setTextColor(SH110X_WHITE);     // Estableciendo el color del texto
  display.setCursor(SCREEN_X, SCREEN_Y);  // Estableciendo la posición del cursor
  display.println(message);               // Mostrando el mensaje de inicializacion
  display.display();                      // Actualizando la pantalla para mostrar el cambio
}

void DISPLAY_OLED::display_clear_screen(void) {
  display.clearDisplay();  // Limpiando la pantalla
  display.display();       // Actualizando la pantalla para mostrar el cambio
}
