/*  EJEMPLO DE USO DEL DISPLAY LCD
  
 * LCD RS pin a digital pin 7
 * LCD Enable pin a digital pin 6
 * LCD D4 pin a digital pin 5
 * LCD D5 pin a digital pin 4
 * LCD D6 pin a digital pin 3
 * LCD D7 pin a digital pin 2
 * LCD R/W pin a masa
 * LCD VSS pin a masa
 * LCD VCC pin a 5V

*/

#include <LiquidCrystal.h>              // libreria de manejo del display

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);    //definimos los pines de la placa al display

int lectura;

void setup() {
  lcd.begin(16, 2);                     //definimos el tipo de display 
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);
}

void loop() {
  lectura = analogRead(A0);
  Serial.println(lectura);
  lcd.setCursor(0, 0);                      //SELECCIONO EL PUNTO 0,0  
  lcd.print("  TEMPERATURA");
  lcd.setCursor(6, 1);                      //CAMBIO A LA SEGUNDA LINEA
  lectura = (5 * lectura * 100)/1024;
  lcd.print(lectura);
  lcd.print(" C");
  delay(1000);                              //espero 1 segundo
}
