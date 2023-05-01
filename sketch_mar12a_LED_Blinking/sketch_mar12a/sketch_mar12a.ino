int count=0;
void setup() {
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(9600);
   
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  //delay(100);
  Serial.print("ON");
  count=count+1;
  digitalWrite(LED_BUILTIN, LOW);
  //delay(5000);
  Serial.print("OFF");
  Serial.print(count);
  Serial.print("\n");
  
}
