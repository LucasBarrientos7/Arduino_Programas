/* Programa de prueba de semaforo
 * 
 */

 #define verde 8
 #define amarillo 7
 #define rojo 6
 #define boton1 10
 #define boton2 11
 #define boton3 12

 char uno, dos, tres;
 
void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, LOW);
}

void loop() {
  uno = digitalRead(boton1);
  dos = digitalRead(boton2);
  tres= digitalRead(boton3);
  if(uno == 0)
    digitalWrite(rojo, HIGH);
  else
    digitalWrite(rojo, LOW);
  if(dos == 0)
    digitalWrite(amarillo, HIGH);
  else
    digitalWrite(amarillo, LOW);
  if(tres == 0)
    digitalWrite(verde, HIGH);
  else
    digitalWrite(verde, LOW);
}
