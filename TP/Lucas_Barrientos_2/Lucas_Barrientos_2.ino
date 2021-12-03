// Trabajo Práctico Nro.2
// Manejo de placa RFID y Display Inteligente

// Librerias:
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

// Variables:
const int RST_PIN = 9;           // Se define el pin digital del pin RST
const int SS_PIN = 10;           // Se define el pin digital del pin SS
MFRC522 lector(SS_PIN, RST_PIN); // Inicializa la placa RFID
LiquidCrystal lcd(2,3,4,5,6,7);  // Se definen los pines digitales del LCD

void setup() {
  pinMode(13, OUTPUT);    
  digitalWrite(13, LOW);        // Se apaga el led de la placa
  Serial.begin(9600);           // Inicializa la velocidad del Serial
  SPI.begin();                  // Funcion que inicializa el SPI
  lector.PCD_Init();            // Funcion que da comienzo a la placa RFID
  lcd.begin(16, 2);             // Inicializar el LCD con el número de columnas y filas del LCD
  lcd.print("Nro de Tarjeta:"); // Se escribe el Mensaje en el LCD
}

void loop() {
  if (lector.PICC_IsNewCardPresent()){              // Detecta si hay Tarjeta
    if (lector.PICC_ReadCardSerial()){              // Lee si hay una Tarjeta
      Serial.print(F("Nro de Tarjeta: "));          // Se escribe el Mensaje en el LCD.
      pSerial(lector.uid.uidByte, lector.uid.size); // Imprime en Monitor Serie
      Serial.println();                             // Salto de linea
      lector.PICC_HaltA();                          // Finaliza la lectura actual
    }
  } else {
     Serial.println(F("..."));                       // Devuelve "..." si el lector no lee nada
  }
  lcd.setCursor(0, 1);                               // El cursor se ubica en la 1ra posición de la 2da fila
  printDisplay(lector.uid.uidByte, lector.uid.size); // Se escribe el Nro de tarjeta en la pantalla del display
  delay(1000);                                       // Velocidad del programa
}

/* Imprime en la pantalla del Monitor Serial el valor hexadecimal de la tarjeta */
void pSerial(byte * buffer, byte bufferSize){
  for(byte i = 0; i < bufferSize; i++){
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/* Imprime en la pantalla del LCD el valor hexadecimal de la tarjeta */
void printDisplay(byte * buffer, byte bufferSize){
  for(byte i = 0; i < bufferSize; i++){
    lcd.print(buffer[i] < 0x10 ? " 0" : " ");
    lcd.print(buffer[i], HEX);
  }
}
