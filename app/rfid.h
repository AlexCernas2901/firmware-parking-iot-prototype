#include <MFRC522.h>
#include <SPI.h>

class RfidReader {
public:
  const uint8_t SSPIN = 29;  // GPIO 5
  const uint8_t RSTPIN = 12; // GPIO 27
  MFRC522 rfid = MFRC522(SSPIN, RSTPIN);

public:
  String init(void);
};

String RfidReader::init(void) {
  SPI.begin();     // init SPI bus
  rfid.PCD_Init(); // init MFRC522
}