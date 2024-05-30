#include <Wire.h>               /*~ Librería I2C ~*/
#include <LiquidCrystal_I2C.h>  /*~ Librería LCD ~*/

LiquidCrystal_I2C lcd (0x27, 16, 2);  /*~ Instancia de la clase para el manejo de la pantalla ( Dirección I2C, cantidad de columnas, cantidad de filas ) ~*/

class DISPLAY_OLED {
public:
  void init(void);
  void printMessage(String message1, String message2);
  void clearScreen();
};

void DISPLAY_OLED::init(void) {
  lcd.init();                    /*~ Inicializar la pantalla LCD ~*/
  lcd.backlight();               /*~ Encender la luz de fondo ~*/
}

void DISPLAY_OLED::printMessage(String message1, String message2) {
  lcd.setCursor(0, 0);           /*~ (columnas, filas) Ubicamos el cursor en la primera posición(columna:0) de la primera línea(fila:0) ~*/
  lcd.print(message1);            // Mostrando el primer mensaje
  lcd.setCursor(0, 1);           /*~ (columnas, filas) Ubicamos el cursor en la primera posición(columna:0) de la primera línea(fila:0) ~*/
  lcd.print(message2);            // Mostrando el segundo mensaje
}


void DISPLAY_OLED::clearScreen(void) {
  lcd.clear();  // Limpia la pantalla LCD
}
