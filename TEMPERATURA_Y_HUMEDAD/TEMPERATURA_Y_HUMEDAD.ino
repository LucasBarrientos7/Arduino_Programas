/*
 * Programa de prueba de la placa del sensor de humedad y temperatura
 * 
 */

  // Incluimos librería
  #include <DHT.h>
 
  // Definimos el pin digital donde se conecta el sensor
  #define DHTPIN 10
  
  // Dependiendo del tipo de sensor hay varios tipos DHT11 y DHT22
  #define DHTTYPE DHT11
 
  // Inicializamos el sensor DHT11
  DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
   // Esperamos 5 segundos entre medidas
  digitalWrite(13, LOW);
  delay(2500);
  digitalWrite(13, HIGH);
  delay(1500);
  
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  } 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C ");
}
