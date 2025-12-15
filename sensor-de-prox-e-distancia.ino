
// tresholds para acender os leds (d é inverso à p)
const int treshold_d1 = 50;
const int treshold_d2 = 250;
const int treshold_d3 = 500;
const int treshold_p1 = 500;
const int treshold_p2 = 250;
const int treshold_p3 = 50;
// define os pinos analógicos da leitura dos ldr
const int ldr1 = A0;
const int ldr2 = A1;
// define a leitura dos sensores
int sensor1;
int sensor2;
// pinos dos leds, 1 e 4 verdes, 2 e 5 amarelos, 3 e 6 vermelhos.
int led1 = 0;
int led2 = 1;
int led3 = 2;
int led4 = 3;
int led5 = 4;
int led6 = 5;
// pinos de saída para o ldr
int vccldr1 = 9;
int vccldr2 = 10;
void setup() {
  // define a comunicação
  Serial.begin(9600);
  // define o que cada pino faz
  pinMode(vccldr1, OUTPUT);
  pinMode(vccldr2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  sensor1 = analogRead(ldr1);
  sensor2 = analogRead(ldr2);
  // mostrar a leitura
  Serial.println(sensor1);
  Serial.println(sensor2);
  //leitura distância 1
if(sensor1>treshold_d1){
  digitalWrite(led1, HIGH);
}
else{
  digitalWrite(led1, LOW);
}
// leitura distância 2
if(sensor1>treshold_d2){
  digitalWrite(led2, HIGH);
}
else{
  digitalWrite(led2, LOW);
}
// leitura distância 3
if(sensor1>treshold_d3){
  digitalWrite(led3, HIGH);
}
else{
  digitalWrite(led3, LOW);
}
// leitura proximidade 1
if(sensor2<treshold_p1){
  digitalWrite(led4, HIGH);
}
else{
  digitalWrite(led4, LOW);
}
// leitura proximidade 2
if(sensor2<treshold_p2){
  digitalWrite(led5, HIGH);
}
else{
  digitalWrite(led5, LOW);
}
// leitura da proximidade 3
if(sensor2<treshold_p3){
  digitalWrite(led6, HIGH);
}
else{
  digitalWrite(led6, LOW);
}
}
