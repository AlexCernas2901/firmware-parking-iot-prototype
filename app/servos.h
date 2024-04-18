#ifndef SERVOS_H
#define SERVOS_H

#include <ESP32Servo.h>

Servo SERVO_ENTRADA;
Servo SERVO_SALIDA;

class Servos {
public:
  void init(void);
  void abrirEntrada(void);
  void cerrarEntrada(void);
  void abrirSalida(void);
  void cerrarSalida(void);
};

void Servos::init(void) {
  SERVO_ENTRADA.attach(17);
  SERVO_SALIDA.attach(33);

  SERVO_ENTRADA.write(0);
  SERVO_SALIDA.write(0);
}

void Servos::abrirEntrada(void) {
  if (digitalRead(SENSOR_ENTRADA_1) == LOW) {
    SERVO_ENTRADA.write(90);
  }
}

void Servos::cerrarEntrada(void) {
  if (digitalRead(SENSOR_ENTRADA_2) == LOW) {
    SERVO_ENTRADA.write(0);
  }
}

void Servos::abrirSalida(void) {
  if (digitalRead(SENSOR_SALIDA_1) == LOW) {
    SERVO_SALIDA.write(90);
  }
}

void Servos::cerrarSalida(void) {
  if (digitalRead(SENSOR_SALIDA_2) == LOW) {
    SERVO_SALIDA.write(0);
  }
}

#endif
