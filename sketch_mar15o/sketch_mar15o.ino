void setup() {
  Serial.begin(9600);
  while(!Serial){
    ; //wait for serial port to connect. Needed for native USB port only
  }
  int x;
  x=-42;
  Serial.print(abs(x));
}

void loop() {
}
