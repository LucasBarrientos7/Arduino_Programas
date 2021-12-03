#include <Servo.h>

 #include <Servo.h>
 
 Servo elservo;  // define el nombre del sistema a la funcion
 
 #define verde 8
 #define amarillo 7
 #define rojo 6
 #define boton1 10
 #define boton2 11
 #define boton3 12

  char uno =0, dos =0, tres =0, pote = A0;  // el potenciometro esta conectado al pin A0;
  int lectura;      // defino la variable de lectura del valor del potenciometro
  
void setup() {
  elservo.attach(9);  // defino que el servo esta conectado al pin 9
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
  lectura = analogRead(pote);                   // leo el valor del potenciometro
  lectura = map(lectura, 0, 1023, 0, 180);     // escalo el valor desde 0 a 1023 a 0 a 180
  elservo.write(lectura);                     // coloco al servo en funcion al valor escalado
  delay(10);
}
