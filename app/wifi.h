#include <WiFi.h>

class WIFI_CONNECTION {
  public:
    const char* SSID = "Megacable_2.4G_C542";
    const char* PASSWORD = "dUnwKs3J";

  public:
    void stablish_connection(void); // Funcion para inicializar la conexion WiFi
};

void WIFI_CONNECTION::stablish_connection(void) {
  WiFi.begin(SSID, PASSWORD);
  delay(1000);
  Serial.print("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nSuccess WiFi connection");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
} 
