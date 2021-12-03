/*
 * EJEMPLO MOSTRAR ID DE LA TARJETA
 */

// RST      D9 NARANJA
// SDA(SS)  D10 VERDE
// MOSI     D11 AZUL
// MISO     D12 AMARILLO
// SCK      D13 VIOLETA

#include <SPI.h>    // libreria de comunicaciones seriales
#include <MFRC522.h>  // libreria de manejo de la placa rc522

const int RST_PIN = 9;  // Pin 9 para el reset del RC522
const int SS_PIN = 10;  // Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); // Crear instancia del MFRC522

void printArray(byte * buffer, byte bufferSize){
  for(byte i = 0; i < bufferSize; i++){
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void setup() {
  Serial.begin(9600); // Inicializa la velocidad del Serial
  SPI.begin();        // Funcion que inicializa el SPI
  mfrc522.PCD_Init(); // Funcion que inicializa RFID
}

void loop() {
  // Detectar Tarjeta
  if (mfrc522.PICC_IsNewCardPresent()){
    if (mfrc522.PICC_ReadCardSerial()){
      Serial.print(F("Card UID: "));
      printArray(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.println();

      // Finalizar lectura actual:
      mfrc522.PICC_HaltA();
    }
  } else {
     //Serial.println(F("No Card"));

  }
  delay(250);
}
