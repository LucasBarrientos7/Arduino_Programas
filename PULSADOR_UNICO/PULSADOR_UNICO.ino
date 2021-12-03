 #define led 5
 #define boton 2
char estado;
 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // Inicializa la velocidad del Serial
 pinMode(led, OUTPUT);
 pinMode(boton, INPUT);
 digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
estado = digitalRead(boton);
Serial.println(estado, DEC);
delay(1000);
  if(estado == 1)
    digitalWrite(led, LOW);
  else
    digitalWrite(led, HIGH);
}
