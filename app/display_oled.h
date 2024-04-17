#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <SPI.h>
#include <Wire.h>

class DisplayOled {
private:
  const uint8_t SCREEN_ADDRESS = 0x3C;
  const uint8_t SCREEN_WIDTH = 128;
  const uint8_t SCREEN_HEIGHT = 64;
  const int8_t OLED_RESET = -1;
  Adafruit_SH1106G oledDisplay = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

public:
  void init();
  void printMessage(const String &message, uint8_t x, uint8_t y);
  void clearScreen();
};

void DisplayOled::init() {
  delay(250);          // Esperando a que el OLED se encienda
  oledDisplay.begin(); // Inicializando la comunicación con la pantalla
}

void DisplayOled::printMessage(const String &message, uint8_t x, uint8_t y) {
  oledDisplay.clearDisplay();             // Limpiando la pantalla
  oledDisplay.setTextSize(1);             // Estableciendo el tamaño del texto
  oledDisplay.setTextColor(SH110X_WHITE); // Estableciendo el color del texto
  oledDisplay.setCursor(x, y);            // Estableciendo la posición del cursor
  oledDisplay.println(message);           // Mostrando el mensaje de inicializacion
  oledDisplay.display();                  // Actualizando la pantalla para mostrar el cambio
}

void DisplayOled::clearScreen() {
  oledDisplay.clearDisplay(); // Limpiando la pantalla
  oledDisplay.display();      // Actualizando la pantalla para mostrar el cambio
}