 // pinos ligados ao sensor
 const int trigger = 10;  // emite o sinal
 const int echo = 11; // recebe o sinal

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // variáveis para calcular a distância
  long duration, cm;
  //controlar os sinais emitidos pelo sensor
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  // calcula a duração do impulso
  duration = pulseIn(echo, HIGH);
  // converte o tempo em distância
  cm = microsecondsToCentimeters(duration);
//demonstra a distância no serial monitor
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
