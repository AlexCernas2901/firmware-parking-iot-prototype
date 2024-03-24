#include <MFRC522.h>
#include <SPI.h>

class RFID {
  // Variables
public:
  const uint8_t SS_PIN = 5;
  const uint8_t RST_PIN = 27;
  MFRC522 rfid = MFRC522(SS_PIN, RST_PIN);

  // Metodos
public:
  String rfid_initialization(void);
};

String RFID::rfid_initialization(void) {
  SPI.begin();      // init SPI bus
  rfid.PCD_Init();  // init MFRC522
}