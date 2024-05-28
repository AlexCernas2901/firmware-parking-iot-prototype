#ifndef APP_DATA_H
#define APP_DATA_H

#include "rtc.h"
DS1307_RTC myrtc; // Instanciando la clase DS1307_RTC

#include "micro_sd.h"
MicroSD MSD; // Instanciando la clase MicroSD


#include "display_oled.h"
DISPLAY_OLED displayOled; // Instanciando la clase DisplayOled

#include "leds.h"
Leds leds; // Instanciando la clase Leds

#include "magnetic_modules.h"
MagneticModules magneticModules; // Instanciando la clase MagneticModules

// #include "wifi.h"
// WifiConnection wifiConnection; // Instanciando la clase WifiConnection

#include "servos.h"
Servos servos; // Instanciando la clase Servos

#include "json.h"
JSON json; // Instanciando la clase JSON

#include "task.h"
millis_tasks TSK; //Instancoando la clase task

//#include "mqtt.h"
//MQTT mqtt; // Instanciando la clase MQTT

#endif
