const int pinLed = 13;
const int pinPing = 7;
const int pinEcho = 6;

void setup() {
  Serial.begin(9600);
  pinMode(pinLed,OUTPUT);
  }

void loop() {
 long duration;
 long cm;

 pinMode(pinPing, OUTPUT);
 digitalWrite(pinPing, LOW);
 delayMicroseconds(2);
 digitalWrite(pinPing, HIGH);
 delayMicroseconds(10);
 digitalWrite(pinPing, LOW);

  pinMode(pinEcho, INPUT);
  duration = pulseIn(pinEcho,HIGH);
  cm = microsecondstoCentimeters(duration);

  if (cm <= 200){
    digitalWrite(pinLed,HIGH);
  }
  else{
    digitalWrite(pinLed,LOW);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
  }

  long microsecondstoCentimeters(long microseconds){
    return microseconds*0.034/2;
  }
