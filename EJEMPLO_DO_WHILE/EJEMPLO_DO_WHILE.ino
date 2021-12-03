/*
 * Programa de ejemplo del uso del do y while
 * Se enciende un led 10 veces y despues se mantiene encendido por 3 segundos y vuelve al ciclo
 */

 #define led 13 //Seleccion la salida del LED

 char cuenta = 0;
 
 void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  do{
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    cuenta++;
  } while (cuenta < 10);
    digitalWrite(led, HIGH);
    delay(3000);
    cuenta = 0;
}
