#ifndef json_h
#define json_h

#include <ArduinoJson.h>

class JSON {
public:
  String data(void);
};


String JSON ::data(void) {
  String temp = "";
  DynamicJsonDocument doc(1024);
  myRTC.get_time();

  doc["fecha"] = String(myRTC.format_date('/'));
  doc["hora"] = String(myRTC.format_time());

  JsonArray sensors = doc.createNestedArray("sensors");

  JsonObject carG1 = sensors.createNestedObject();
  carG1["type"] = "general";
  carG1["state"] = carStatesG[0];

  JsonObject carG2 = sensors.createNestedObject();
  carG2["type"] = "general";
  carG2["state"] = carStatesG[1];

  JsonObject carD1 = sensors.createNestedObject();
  carD1["type"] = "disabilities";
  carD1["state"] = carStatesD[0];


  serializeJson(doc, temp);
  // Serial.println ( temp );
  return temp;
}

#endif
