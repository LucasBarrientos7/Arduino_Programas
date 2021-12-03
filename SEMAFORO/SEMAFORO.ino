/*
 * Semaforo con 3 leds
 */
 
 #define rojo 6
 #define amarillo 7
 #define verde 8
 
 void setup() {
  // put your setup code here, to run once:
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);  
  pinMode(verde, OUTPUT);
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(verde, HIGH);
  delay(4000);
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, HIGH);
  delay(1500);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, HIGH);
  delay(4000);
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, HIGH);
  delay(1500);
  digitalWrite(amarillo, LOW);
}
