void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int val=analogRead(0);
  val=map(val,0,1023,0,255); //map an analog value to 8 bits
  analogWrite(9,val);
}
