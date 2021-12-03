// Trabajo Practico Nro.1
// Manejo de entradas salidas y servo motor

// Librerias:
#include <Servo.h>

// Botones:
#define botonROJO 2
#define botonVERDE 3
#define botonAMARILLO 4

// LEDs:
#define ledROJO 5
#define ledVERDE 6
#define ledAMARILLO 7

// Variables:
Servo servomotor; // Se define el nombre del servomotor
int estado;       // Se guarda el estado del led (Encendido/Apagado)
 
void setup() {
 pinMode(ledROJO, OUTPUT);
 pinMode(ledVERDE, OUTPUT);
 pinMode(ledAMARILLO, OUTPUT);
 pinMode(botonAMARILLO, INPUT);
 pinMode(botonVERDE, INPUT);
 pinMode(botonROJO, INPUT);
 pinMode(13, OUTPUT);    
 digitalWrite(13, LOW); // Se apaga el led de la placa
 Serial.begin(9600);    // Inicializa la velocidad del Serial
 servomotor.attach(9);  // Se define el pin digital del servomotor
 ledsApagados();        // Apaga todos los leds al inicializar
}

void loop() {
// 0 == Encendido
// 1 == Apagado

  if(lecturaDelEstado(botonROJO) == 1){
    encenderYMover(ledROJO,ledAMARILLO,ledVERDE, 0);
    Serial.println("Boton: 2\nLED: Rojo\nGrados: 0°\n");
    delay(10);
  }  
  if(lecturaDelEstado(botonVERDE) == 1){
    encenderYMover(ledVERDE,ledROJO,ledAMARILLO, 90);
    Serial.println("Boton: 3\nLED: Verde\nGrados: 90°\n");
    delay(10);
  }  
  if(lecturaDelEstado(botonAMARILLO) == 1){
    encenderYMover(ledAMARILLO,ledROJO,ledVERDE, 180);
    Serial.println("Boton: 4\nLED: Amarillo\nGrados: 180°\n");
    delay(10);
  }
}

/* Lee el valor digital del boton y lo intercambia por el valor opuesto */
int lecturaDelEstado(int boton) {
  int lectura = digitalRead(boton);
  if(lectura == 0) {
    return 1;
  } else {
      return 0;
  }
}

/* Se encarga de mantener encendido el LED pulsado  y apagar los LEDs restantes */
void encenderYMover(int ledEncendido, int ledApagado1, int ledApagado2, int grados){
    digitalWrite(ledEncendido, HIGH);
    digitalWrite(ledApagado1, LOW);
    digitalWrite(ledApagado2, LOW);
    servomotor.write(grados);
}

/* Apaga todos los LEDs */
void ledsApagados(){
    digitalWrite(ledROJO, LOW);
    digitalWrite(ledVERDE, LOW);
    digitalWrite(ledAMARILLO, LOW);
}
