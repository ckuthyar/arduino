unsigned long time1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Time:");
  time1=micros(); //returns the number of microseconds since the Arduino board began
  Serial.print(time1);
  delay(1000);
}
