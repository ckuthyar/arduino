

void setup() {
  Serial.begin(9600);
}

void loop() {
  analogReadResolution(10);
  Serial.print("ADC 10-bit default: ");
  Serial.print(analogRead(A0));

  delay(100);

  analogReadResolution(12);
  Serial.print(", 12-bit: ");
  Serial.print(analogRead(A0));
}
