//pinos das cores do led rgb, eles devem ser conectados aos pinos PWM
 const int pino_vermelho = 11;
 const int pino_verde = 10;
 const int pino_azul = 9;
//pinos analógicos dos potenciômetros
 const int pot_azul = A0;
 const int pot_verde = A1;
 const int pot_vermelho = A2;
// variáveis para operações
int lp1;
int lp2;
int lp3;
int vermelho;
int azul;
int verde;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  //leitura dos potenciômetros
  lp1 = analogRead(pot_azul);
  lp2 = analogRead(pot_verde);
  lp3 = analogRead(pot_vermelho);

// converter os valores da leitura analógica 0-1023 para 0-255
  azul = map(lp1,0,1023,0,255);
  verde = map(lp2,0,1023,0,255);
  vermelho = map(lp3,0,1023,0,255);

// inserir esses valores nos pinos
   analogWrite(pino_azul, azul);
   analogWrite(pino_verde, verde);
   analogWrite(pino_vermelho, vermelho);

// mostrar os valores rgb no serial monitor
Serial.print("RGB: ");
Serial.print(vermelho);
Serial.print(" ");
Serial.print(verde);
Serial.print(" ");
Serial.println(azul);

}
