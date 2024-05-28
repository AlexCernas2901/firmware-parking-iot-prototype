#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

class DISPLAY_OLED {
public:
  const uint8_t SCREEN_ADDRESS = 0x3C;
  const uint8_t SCREEN_WIDTH = 128;
  const uint8_t SCREEN_HEIGHT = 64;
  const int8_t OLED_RESET = -1;
  Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

public:
  void init(void);
  void printMessage(String message);
  void clearScreen(void);
};

void DISPLAY_OLED::init(void) {
  delay(250);       // Esperando a que el OLED se encienda
  display.begin();  // Inicializando la comunicación con la pantalla
}

void DISPLAY_OLED::printMessage(String message) {
  display.clearDisplay();              // Limpiando la pantalla
  display.setTextSize(1);              // Estableciendo el tamaño del texto
  display.setTextColor(SH110X_WHITE);  // Estableciendo el color del texto
  display.setCursor(0, 0);             // Estableciendo la posición del cursor
  display.println(message);            // Mostrando el mensaje de inicializacion
  display.display();                   // Actualizando la pantalla para mostrar el cambio
}

void DISPLAY_OLED::clearScreen(void) {
  display.clearDisplay();  // Limpiando la pantalla
  display.display();       // Actualizando la pantalla para mostrar el cambio
}
