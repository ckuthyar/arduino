void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  int sensorVal=analogRead(A0);
  Serial.print("Analog Read:");
  Serial.print(sensorVal);

  analogWriteResolution(8); //supported only in Due
  analogWrite(11,map(sensorVal,0,1023,0,255);
  Serial.print("8 bit PWM value");
  Serial.print(map(sensorVal,0,1023,0,255);

  analogWriteResolution(12);
  analogWrite(12,map(sensorVal,0,1023,0,4095);
  Serial.print("12 bit PWM value");
  Serial.print(map(sensorVal,0,1023,0,4095));

  analogWriteResolution(4);
  analogWrite(13,map(sensorVal,0,1023,0,15);
  Serial.print("4 bit PWM value");
  Serial.print(map(sensorVal,0,1023,0,15));
  
  delay(5);
}
