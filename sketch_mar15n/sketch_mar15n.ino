unsigned long myTime;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Time:");
  myTime=millis();
  Serial.println(myTime);
  delay(1000);

}
