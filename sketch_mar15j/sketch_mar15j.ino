int latchPin=8;  //connected to ST_CP of 74HC95
int clockPin=12; //connected to SH_CP of 74HC95
int dataPin=11; //connected to DS of 74HC95

void setup() {
  pinMode(latchPin,OUTPUT);   //set pins to output
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop() {
  for (int j=0;j<256;j++){    //count up
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,LSBFIRST,j);
    digitalWrite(latchPin,HIGH);
    delay(1000);
  }
}

//ground latchPin held low during transmitting
