/*
 * EJEMPLO DEL USO DE UNA PLACA RFID-RC522 COMO LECTORA DE TARJETAS
 */

#include <SPI.h>    // libreria de comunicaciones seriales
#include <MFRC522.h>  // libreria de manejo de la placa rc522

#define SS_PIN 10   // definimos los pines de comunicacion
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 
String card_ID=""; 

void setup() {
  Serial.begin(9600);  //CONFIGURACION DE LOS PUERTOS SERIALES
  SPI.begin();  
  mfrc522.PCD_Init();  //INICIALIZACION DE LA PLACA
  delay(200);
   }
   
void loop() {
  
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;
 }
 
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;
 }

 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID += mfrc522.uid.uidByte[i];
 }
 
  Serial.println(card_ID);
  card_ID="";
  delay(1000);
 
}
    
