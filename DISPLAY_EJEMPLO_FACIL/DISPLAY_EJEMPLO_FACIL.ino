#include <LiquidCrystal.h>
// VSS  VDD   RS  RW   E         D4  D5  D6  D7  A K
// GND   +    02  GND  03        04  05  06  07  + -
//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);
  // Escribimos el Mensaje en el LCD.
  lcd.print("    BOMB HAS  ");

}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);
   // Escribimos el número de segundos trascurridos
  //lcd.print(millis()/1000);
  lcd.print("  BEEN PLANTED ");
  delay(1000);
}