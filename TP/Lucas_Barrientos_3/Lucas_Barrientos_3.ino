// Trabajo Práctico Nro.3
// Sistema de control de temperatura

// Librerías:
#include <DHT.h>
#include <Servo.h>
#include <LiquidCrystal.h>

#define DHTPIN 10     // Se define el pin digital del sensor DHT
#define DHTTYPE DHT11 // Tipo de sensor
 
// Variables:
DHT dht(DHTPIN, DHTTYPE);       // Inicializa el sensor DHT11
Servo servomotor;               // Se define el nombre del servomotor
LiquidCrystal lcd(2,3,4,5,6,7); // Se definen los pines digitales del LCD
char potenciometro = A0;        // Se define el pin analogico del potenciometro
int lectura;                    // Guarda el valor dado por el potenciometro
int tempSet;                    // Guarda el valor de la temperatura interna

void setup() {   
  pinMode(13, OUTPUT);    
  digitalWrite(13, LOW); // Se apaga el led de la placa 
  Serial.begin(9600);    // Inicializa la velocidad del serial
  servomotor.attach(9);  // Se define el pin digital del servomotor
  dht.begin();           // Da comienzo al sensor DHT
  lcd.begin(16, 2);      // Inicializar el LCD con el número de  columnas y filas del LCD
}

void loop() {
  lectura = analogRead(potenciometro);     // Lectura del valor del potenciometro
  lectura = map(lectura, 0, 1023, 0, 100); // Escalo el valor desde 0 a 1023 a 0 a 180
  tempSet = map(lectura, 0, 101, 12, 36);  // Escalo el valor desde 0 a 101 a 12 a 36
  servomotor.write(lectura);               // Mueve el servomotor al valor leido
  int t = dht.readTemperature();           // Lectura de la temperatura en grados °C
  printLCD(lectura, t, tempSet);           // Imprime en LCD
  printMonitorSerie(lectura, t, tempSet);  // Imprime en Monitor Serie
  delay(1000);                             // Velocidad del programa
}

/* Imprime en la pantalla del Display la apertura de la ventana, temperatura y temperatura interna */
void printLCD(int apertura, int temp, int tempInterna){
  lcd.setCursor(1, 0);
  lcd.print(apertura);
  lcd.print("% de Apertura");
  lcd.setCursor(0, 1);
  lcd.print("TM:");
  lcd.print(temp);
  lcd.print("*C  TS:");
  lcd.print(tempInterna);
  lcd.print("*C");
}

/* Imprime en el Monitor Serie la apertura de la ventana, temperatura y temperatura interna */
void printMonitorSerie(int apertura, int temp, int tempInterna){
  Serial.print(apertura);
  Serial.println("% de Apertura de Ventana");
  Serial.print("Temperatura medida: ");
  Serial.print(temp);
  Serial.print("*C / Temperatura Seteada: ");
  Serial.print(tempInterna);
  Serial.println("*C");
  Serial.println();
}
