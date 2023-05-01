//Mario's Ideas
//MAX7219 - using Led Control library to display all   leds one by one
#include <LedControl.h>

int DIN = 11;
int CS = 10;
int   CLK = 13; 
LedControl lc=LedControl(DIN, CLK, CS,0);

void setup()   {
lc.shutdown(0,false);
lc.setIntensity(0,0);
lc.clearDisplay(0);  
}

void   loop() {
//lc.clearDisplay(0);
five();
delay(1000);
//lc.setLed(0,4,5,true);
}


int i=0;
int j=0;
void five(){

int row1[8]={0,0,0,0,0,0,0,0};
int row2[8]={0,0,1,1,1,1,1,0};
int row3[8]={0,0,1,0,0,0,0,0};
int row4[8]={0,0,1,1,1,1,0,0};
int row5[8]={0,0,0,0,0,0,1,0};
int row6[8]={0,0,0,0,0,0,1,0};
int row7[8]={0,0,1,1,1,1,0,0};
int row8[8]={0,0,0,0,0,0,0,0};

for(int i=0; i<8; i++){
  lc.setLed(0,0,i,row1[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,1,i,row2[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,2,i,row3[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,3,i,row4[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,4,i,row5[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,5,i,row6[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,6,i,row7[i]);
}
for(int i=0; i<8; i++){
  lc.setLed(0,7,i,row8[i]);
}
  


}
