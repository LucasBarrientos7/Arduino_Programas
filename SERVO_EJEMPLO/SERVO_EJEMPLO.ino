#include <Servo.h>

Servo elservo;  // define el nombre del sistema a la funcion
int grado;

void setup() {
  Serial.begin(9600);
  elservo.attach(9);  // defino que el servo esta conectado al pin 9
}

void loop() {
  grado = 40;
  elservo.write(grado);                     // coloco al servo en funcion al valor escalado
  delay(100);                                  // espero un poquito a que el servo responda
  Serial.println(grado);
}
