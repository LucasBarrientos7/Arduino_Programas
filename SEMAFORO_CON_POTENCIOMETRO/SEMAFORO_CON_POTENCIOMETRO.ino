/*
 * Semaforo con 3 leds y con potenciometro para regular el delay
 */
 
#define rojo 6
#define amarillo 7
#define verde 8
#define pote A0
int lectura;
 
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
  lectura = analogRead(A0);
  digitalWrite(verde, HIGH);
  delay(lectura*2);
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, HIGH);
  delay(lectura);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, HIGH);
  delay(lectura*2);
  digitalWrite(rojo, LOW);
}
