#ifndef RTC_H
#define RTC_H

#include <Wire.h>  // Librería para el uso del protocolo I2C
#include "RTClib.h"  // Librería para usar el RTC

RTC_DS1307 rtc;

class DS1307_RTC {
public:
    uint8_t hora = 0, minuto = 0, segundo = 0, dia = 0, mes = 0;
    uint16_t ano = 0;
    String fecha = "", tiempo = "";

public:
    void init(void);
    void get_time(void);  // Cambiado de String a void ya que no devuelve nada
    String format_date(char caracter);
    String format_time(void);
    void show_time(void);
};

// Función que configura lo necesario para que el reloj se inicialice
void DS1307_RTC::init(void) {
    while (!rtc.begin()) {  // Mientras que el reloj no se ha iniciado
        Serial.println(F("Hay un error de reconocimiento del RTC, revisa conexiones y alimentación"));
        Serial.flush();  // Espera a que se transmita la información serial correctamente
        delay(3000);
    }
    if (!rtc.isrunning()) {  // Si el reloj no está ejecutándose
        Serial.println(F("El reloj se está configurando con la fecha y hora de la computadora"));
        // __DATE__ y __TIME__ Son macros que retornan la fecha y hora de la computadora
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Ajusta automáticamente la fecha y hora
    }
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));  // Ajusta manualmente la fecha y hora
}

// Función para obtener la hora actual del RTC
void DS1307_RTC::get_time(void) {
    DateTime now = rtc.now();
    segundo = now.second();
    minuto = now.minute();
    hora = now.hour();
    dia = now.day();
    mes = now.month();
    ano = now.year();
}

// Función que le da un formato legible a la fecha
String DS1307_RTC::format_date(char caracter) {
    fecha = "";
    if (dia < 10) fecha += '0';
    fecha += dia;
    fecha += caracter;
    if (mes < 10) fecha += '0';
    fecha += mes;
    fecha += caracter;
    fecha += ano;

    return fecha;
}

// Función que le da un formato legible al tiempo
String DS1307_RTC::format_time(void) {
    tiempo = "";
    if (hora < 10) tiempo += '0';
    tiempo += hora;
    tiempo += ':';
    if (minuto < 10) tiempo += '0';
    tiempo += minuto;
    tiempo += ':';
    if (segundo < 10) tiempo += '0';
    tiempo += segundo;

    return tiempo;
}

// Función que muestra en la consola serial la fecha y la hora
void DS1307_RTC::show_time(void) {
    format_time();  // Dar formato al tiempo
    Serial.print(F("Hora: "));
    Serial.println(tiempo);
    format_date('/');
    Serial.print(F("Fecha: "));
    Serial.println(fecha);  // Dar formato a la fecha
}

#endif
