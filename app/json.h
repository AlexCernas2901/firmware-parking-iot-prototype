#ifndef json_h
#define json_h

#include <ArduinoJson.h>

class JSON {
public:
  String cars_json();
};

String JSON ::cars_json() {
  String temp = "";
  DynamicJsonDocument doc(1024);

  JsonArray array = doc.to<JsonArray>();

  JsonObject carG1 = array.createNestedObject();
  carG1["type"] = "general";
  carG1["state"] = carStates[0];

  JsonObject carG2 = array.createNestedObject();
  carG2["type"] = "general";
  carG2["state"] = carStates[1];

  JsonObject carD1 = array.createNestedObject();
  carD1["type"] = "disabilities";
  carD1["state"] = carStatesD[0];


  serializeJson(doc, temp);
  serializeJsonPretty(doc, temp);
  //Serial.begin ( 115200 );
  // Serial.println ( F ( "Json anidados:" ) );
  // Serial.println ( temp );
  return temp;
}

#endif
