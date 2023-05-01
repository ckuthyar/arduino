int pin=7;
unsigned long duration;

void setup() {
  Serial.begin(9600);
  pinMode(pin,INPUT);
}

void loop() {
  duration=pulseIn(pin,HIGH);  //length of the pulse in uSeconds
  Serial.println(duration);
}
