/*
 * Programa de ejemplo del uso del if/else
 */

 #define led 13 // Selecciono la salida del LED

 char cuenta = 0;
 
void setup() {
  // Poner agui todo l o referente a configuracion del sistema y se ejecuta al principio por unica vez
  pinMode(led, OUTPUT);
}

void loop() {
  // Poner aqui el codigo que se va a ejecutar constantemente en forma de ciclo

  if(cuenta != 10){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    cuenta++;
  } else {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
    cuenta = 0;
  }
}
