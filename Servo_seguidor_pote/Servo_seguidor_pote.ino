/*
  Este programa funciona con un potenciometro conectado al A0 y el servo al pin 9
  Y el motor sigue la posicion del potenciometro
*/

#include <Servo.h>

Servo elservo;  // define el nombre del sistema a la funcion

char pote = A0;  // el potenciometro esta conectado al pin A0
int lectura;      // defino la variable de lectura del valor del potenciometro

void setup() {
  elservo.attach(9);  // defino que el servo esta conectado al pin 9
}

void loop() {
  lectura = analogRead(pote);                   // leo el valor del potenciometro
  lectura = map(lectura, 0, 1023, 0, 180);     // escalo el valor desde 0 a 1023 a 0 a 180
  elservo.write(lectura);                     // coloco al servo en funcion al valor escalado
  delay(10);                                  // espero un poquito a que el servo responda
}
