#include <MFRC522.h>
#include <SPI.h>

class Rfid {
  // Variables
public:
  const uint8_t SS_PIN = 29;   // GPIO 5
  const uint8_t RST_PIN = 12;  // GPIO 27
  MFRC522 rfid = MFRC522(SS_PIN, RST_PIN);

  // Metodos
public:
  String rfid_initialization(void);
};

String Rfid::rfid_initialization(void) {
  SPI.begin();      // init SPI bus
  rfid.PCD_Init();  // init MFRC522
}