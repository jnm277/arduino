// inclui a biblioteca servo.h
#include <Servo.h>
 
// define a quantidade de servos
#define SERVOS 2

// cria os objetos servo
Servo myservo[SERVOS];  
 
// define os pinos onde os servos serão conectados
int servo_pins[SERVOS] = {3,6}; 
 
// define os pinos analógicos onde os potenciômetros serão conestados
int potpins[SERVOS] = {A0,A1}; 
 
// define a variável para ler os pinos analógicos
int potpin_val[SERVOS]; 
 
void setup() {
   
  for(int i = 0; i < SERVOS; i++) {
     
    // Conecta os servos aos objetos
    myservo[i].attach(servo_pins[i]);  
  }
}
  
void loop() {  
 
  // Movimentos para cada servo
  for(int i = 0; i < SERVOS; i++) {
    // Lê os valores do pinos analógicos (entre 0 e 1023)
    potpin_val[i] = analogRead(potpins[i]); 
 
    // Escala os valores para 0 e 180
    potpin_val[i] = map(potpin_val[i], 0, 1023, 0, 180);
 
    // Atualiza a posição do servo
    myservo[i].write(potpin_val[i]);  
     
    // Espera de 15ms para atualizar a posição
    delay(15);  
  }  
}       