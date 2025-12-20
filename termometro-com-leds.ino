//limites para os leds
int frio = 20;
int normal = 25;
int quente = 30;
int QUENTE = 40;
// pinos dos leds
int led1 = 1;
int led2 = 2;
int led3 = 3;
//pino do buzzer
int buzzer = 8;
// parâmetros do termistor
#define RT0 10000
#define B 3977
// valor do resistor em série
#define R 10000  
// variáveis para os cálculos 
float RT, VR, ln, TX, T0, VRT;
void setup() {
  //define a função dos pinos
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  // Inicia a comunicação
  Serial.begin(9600);
  // converter T0 de celsius para Kelvin
  T0 = 25 + 273.15;
}

void loop() {
// Leitura da corrente
  VRT = (5.00 / 1023.00) * analogRead(A0);
  // calcular a corrente entre o resistor
  VR = 5.00 - VRT;
  // calcular a resistência do termistor
  RT = VRT / (VR / R);
  // calcular a temperatura de acordo com a resistência do termistor
  ln = log(RT / RT0);
  TX = (1 / ((ln / B) + (1 / T0)));
  // converter de kelvin para celsius
  TX = TX - 273.15;
  Serial.print("Temperature: ");
  // mostra a temperatura em celsius
  Serial.print(TX);                  
  Serial.print("C\t");
  // converte e mostra em kelvin
  Serial.print(TX + 273.15);
  Serial.print("K\t");
  // converter e mostrar em fahrenheit 
  Serial.print((TX * 1.8) + 32);
  Serial.println("F");
  delay(500);
  // utiliza 
  if(TX>frio){
    digitalWrite(led1, HIGH);
  }
  else{}

  if(TX>normal){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else{}

  if(TX>quente){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }

  if(TX>QUENTE){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else {}
}

