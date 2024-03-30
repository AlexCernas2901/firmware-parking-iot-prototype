#include <WiFi.h>

class WIFI_CONNECTION {
  // Variables
public:
  const char* SSID = "";  // Nombre de la red
  const char* PASSWORD = "";         // Contraseña de la red

  // Metodos
public:
  void stablish_connection(void);      // Funcion para inicializar la conexion WiFi
  String get_connection_status(void);  // Funcion para obtener el estado de la conexión WiFi
};

void WIFI_CONNECTION::stablish_connection(void) {
  WiFi.begin(SSID, PASSWORD);
  delay(1000);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nSuccess WiFi connection");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

String WIFI_CONNECTION::get_connection_status(void) {
  if (WiFi.status() == WL_CONNECTED) {
    return "Connected to WiFi";
  } else {
    return "WiFi connection failed!";
  }
}
