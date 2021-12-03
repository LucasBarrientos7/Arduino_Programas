/*
 * Programa de ejemplo del uso del do y while
 * Se enciende un led 10 veces y despues se mantiene encendido por 3 segundos y vuelve al ciclo
 */
 
 #define led 13 //Seleccion la salida del LED

 char cuenta = 0;
 
 void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (cuenta = 0; cuenta <= 9; cuenta++){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    Serial.print(cuenta, DEC);
  }
    digitalWrite(led, HIGH);
    delay(3000);
    cuenta = 0;
    digitalWrite(led, LOW);
    delay(200);
}
