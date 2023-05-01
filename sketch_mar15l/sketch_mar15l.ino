int outPin=8;

void setup() {
  pinMode(outPin,OUTPUT);
}

void loop() {
  digitalWrite(outPin,HIGH);
  delayMicroseconds(50);
  digitalWrite(outPin,LOW);
  delayMicroseconds(50);
}
