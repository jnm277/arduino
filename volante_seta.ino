const int esquerda = 248;
const int direita = 775;
int sensor;
int sensor_pin = A0;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 8;
int led5 = 9;
int led6 = 10;


void setup () {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

}

void loop (){
  int sensor = analogRead(sensor_pin);
  Serial.println(sensor);
  if(sensor<esquerda){

    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    delay(100);

  }
  else {

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

  }


  if(sensor>direita){

    digitalWrite(led4, HIGH);
    delay(100);
    digitalWrite(led4,LOW);
    delay(100);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led5,LOW);
    delay(100);
    digitalWrite(led6, HIGH);
    delay(100);
    digitalWrite(led6,LOW);
    delay(100);
  }

  else {
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
  }

}