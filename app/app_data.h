#ifndef APP_DATA_H
#define APP_DATA_H

#include "rtc.h"
DS1307_RTC myrtc; // Instanciando la clase DS1307_RTC

#include "display_oled.h"
DisplayOled displayOled; // Instanciando la clase DisplayOled

#include "magnetic_modules.h"
MagneticModules magneticModules; // Instanciando la clase MagneticModules

#include "wifi.h"
WifiConnection wifiConnection; // Instanciando la clase WifiConnection

#include "servos.h"
Servos servos; // Instanciando la clase Servos

#endif
  