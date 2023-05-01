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

lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);

  
lc.setLed(0,1,0,false);
lc.setLed(0,1,1,false);
lc.setLed(0,1,2,true);
lc.setLed(0,1,3,true);
lc.setLed(0,1,4,true);
lc.setLed(0,1,5,true);
lc.setLed(0,1,6,true);
lc.setLed(0,1,7,false);

lc.setLed(0,2,0,false);
lc.setLed(0,2,1,false);
lc.setLed(0,2,2,true);
lc.setLed(0,2,3,false);
lc.setLed(0,2,4,false);
lc.setLed(0,2,5,false);
lc.setLed(0,2,6,false);
lc.setLed(0,2,7,false);

lc.setLed(0,3,0,false);
lc.setLed(0,3,1,false);
lc.setLed(0,3,2,true);
lc.setLed(0,3,3,true);
lc.setLed(0,3,4,true);
lc.setLed(0,3,5,true);
lc.setLed(0,3,6,false);
lc.setLed(0,3,7,false);

lc.setLed(0,4,0,false);
lc.setLed(0,4,1,false);
lc.setLed(0,4,2,false);
lc.setLed(0,4,3,false);
lc.setLed(0,4,4,false);
lc.setLed(0,4,5,false);
lc.setLed(0,4,6,true);
lc.setLed(0,4,7,false);

lc.setLed(0,5,0,false);
lc.setLed(0,5,1,false);
lc.setLed(0,5,2,false);
lc.setLed(0,5,3,false);
lc.setLed(0,5,4,false);
lc.setLed(0,5,5,false);
lc.setLed(0,5,6,true);
lc.setLed(0,5,7,false);

lc.setLed(0,6,0,false);
lc.setLed(0,6,1,false);
lc.setLed(0,6,2,true);
lc.setLed(0,6,3,true);
lc.setLed(0,6,4,true);
lc.setLed(0,6,5,true);
lc.setLed(0,6,6,false);
lc.setLed(0,6,7,false);

}
