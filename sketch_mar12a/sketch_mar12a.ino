void setup() {
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(9600)
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  Serial.print("ON");
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  Serial.print("OFF")
}
