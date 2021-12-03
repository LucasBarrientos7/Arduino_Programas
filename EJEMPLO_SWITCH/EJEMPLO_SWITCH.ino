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
  switch(cuenta){
    case 0:
      Serial.print(cuenta, DEC);
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      cuenta++;
    break;
    case 1:
      Serial.print(cuenta, DEC);
      digitalWrite(led, HIGH);
      delay(900);
      digitalWrite(led, LOW);
      delay(900);
      cuenta++;
    break;
    case 2:
      Serial.print(cuenta, DEC);
      digitalWrite(led, HIGH);
      delay(1200);
      digitalWrite(led, LOW);
      delay(1200);
      cuenta++;
    break;
    case 3:
      Serial.print(cuenta, DEC);
      digitalWrite(led, HIGH);
      delay(1500);
      digitalWrite(led, LOW);
      delay(1500);
      cuenta++;
    break;
    default:
      Serial.print(cuenta, DEC);
      digitalWrite(led, HIGH);
      delay(3000);
      digitalWrite(led, LOW);
      delay(200);
      cuenta++;
    break;
  }
}
