#include <Wire.h>
#include <Adafruit_SSD1306.h>

class DISPLAY_OLED {
  public: 
    const uint8_t SCREEN_ADDRESS = 0x3C;

  public:
    void display_initialization(void);
};

void DISPLAY_OLED::display_initialization(void) {
  const uint8_t SCREEN_WIDTH = 128;
  const uint8_t SCREEN_HEIGHT = 64;
  const int8_t OLED_RESET = -1;

  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();
}
