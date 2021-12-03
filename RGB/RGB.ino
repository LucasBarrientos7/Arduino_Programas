/*
 * EJEMPLO DEL USO DE PWM HACIENDO FADE DE UN LED RGB
 */

int led1 = 9, led2 = 10, led3 = 11, valor;

void setup() {
  
}

void loop() {
  // hace un fade desde un minimo a un maximo con saltos de 5
  for (valor = 0 ; valor <= 255; valor += 5) {
    analogWrite(led1, valor);
    delay(50);
  }
  // hace un fade desde un maximo a un minimo con saltos de 5
  for (valor = 255 ; valor >= 0; valor -= 5) {
    analogWrite(led1, valor);
    delay(50);  
  }

  for ( valor = 0 ; valor <= 255; valor += 5) {
    analogWrite(led2, valor);
    delay(50);
  }

  for (valor = 255 ; valor >= 0; valor -= 5) {
    analogWrite(led2, valor);
    delay(50);
  }

  for (valor = 0 ; valor <= 255; valor += 5) {
    analogWrite(led3, valor);
    delay(50);
  }

  for (valor = 255 ; valor >= 0; valor -= 5) {
    analogWrite(led3, valor);
    delay(50);
  }
}
