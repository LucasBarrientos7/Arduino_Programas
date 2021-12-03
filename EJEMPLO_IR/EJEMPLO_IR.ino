#include <IRremote.h>

int pin_recibe = 2;
IRrecv irrecibe(pin_recibe);
decode_results resultado;
#define CH1 0xFFA25D 
#define CH 0xFF629D
#define CH2 0xFFE21D
#define OCHO 0xFF4AB5
#define NUEVE 0xFF52AD

#define MENOR  0xFF22DD
#define MAYOR  0xFF02FD
#define PARAR 0xFFC23D
#define MENOS 0xFFE01F
#define MAS 0xFFA857
#define EQ  0xFF906F
#define CIEN  0xFF9867
#define DOCIENTOS  0xFFB04F
#define CERO 0XFF6897
#define UNO 0xFF30CF
#define DOS 0xFF18E7
#define TRES 0xFF7A85
#define CUATRO 0xFF10EF
#define CINCO 0xFF38C7
#define SEIS 0xFF5AA5
#define SIETE 0xFF42BD

void setup(){
 Serial.begin(9600);
 irrecibe.enableIRIn(); 

}

void loop(){
  if (irrecibe.decode(&resultado)){
      switch (resultado.value){
        case CH1:
        Serial.println("CH-");
        irrecibe.resume();
        delay(500);
        break;

        case CH:
        Serial.println("CH");
        irrecibe.resume();
        delay(500);        
        break;
        
        case CH2:
        Serial.println("CH+");
        irrecibe.resume();
        delay(500);
        break;
        
        case OCHO:
        Serial.println(" 8 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case NUEVE:
        Serial.println(" 9 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case MENOR:
        Serial.println(" < ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case MAYOR:
        Serial.println(" > ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case MENOS:
        Serial.println(" - ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case MAS:
        Serial.println(" + ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case EQ:
        Serial.println(" = ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case CIEN:
        Serial.println(" 100 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case DOCIENTOS:
        Serial.println(" 200");
        irrecibe.resume();
        delay(500);
        break;  
        
        case CERO:
        Serial.println(" 0 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case UNO:
        Serial.println(" 1 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case DOS:
        Serial.println(" 2 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case TRES:
        Serial.println(" 3 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case CUATRO:
        Serial.println(" 4 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case CINCO:
        Serial.println(" 5 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case SEIS:
        Serial.println(" 6 ");
        irrecibe.resume();
        delay(500);
        break;  
        
        case SIETE:
        Serial.println(" 7 ");
        irrecibe.resume();
        delay(500);
        break;                                                                                                                                                  
        
        default:
        Serial.println(""); 
        irrecibe.resume();
        delay(500);
        break;
      }
  }
      
 /*     
      if (resultado.value == CH1){
        Serial.println("CH-"); 
      }

      if (resultado.value == CH){
        Serial.println("CH"); 
      }

      if (resultado.value == CH2){
        Serial.println("CH+"); 
      }

      if (resultado.value == OCHO){
        Serial.println("BOTON 8"); 
      }
      
      if (resultado.value == NUEVE){
        Serial.println("BOTON 9"); 
      }
      irrecibe.resume();

    }*/
}
