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



lc.setLed(0,0,0,0);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);
lc.setLed(0,0,0,false);

  
lc.setLed(0,1,0,0);
lc.setLed(0,1,1,0);
lc.setLed(0,1,2,1);
lc.setLed(0,1,3,1);
lc.setLed(0,1,4,1);
lc.setLed(0,1,5,1);
lc.setLed(0,1,6,1);
lc.setLed(0,1,7,0);

lc.setLed(0,2,0,0);
lc.setLed(0,2,1,0);
lc.setLed(0,2,2,1);
lc.setLed(0,2,3,0);
lc.setLed(0,2,4,0);
lc.setLed(0,2,5,0);
lc.setLed(0,2,6,0);
lc.setLed(0,2,7,0);

lc.setLed(0,3,0,0);
lc.setLed(0,3,1,0);
lc.setLed(0,3,2,1);
lc.setLed(0,3,3,1);
lc.setLed(0,3,4,1);
lc.setLed(0,3,5,1);
lc.setLed(0,3,6,0);
lc.setLed(0,3,7,0);

lc.setLed(0,4,0,0);
lc.setLed(0,4,1,0);
lc.setLed(0,4,2,0);
lc.setLed(0,4,3,0);
lc.setLed(0,4,4,0);
lc.setLed(0,4,5,0);
lc.setLed(0,4,6,1);
lc.setLed(0,4,7,0);

lc.setLed(0,5,0,0);
lc.setLed(0,5,1,0);
lc.setLed(0,5,2,0);
lc.setLed(0,5,3,0);
lc.setLed(0,5,4,0);
lc.setLed(0,5,5,0);
lc.setLed(0,5,6,1);
lc.setLed(0,5,7,0);

lc.setLed(0,6,0,0);
lc.setLed(0,6,1,0);
lc.setLed(0,6,2,1);
lc.setLed(0,6,3,1);
lc.setLed(0,6,4,1);
lc.setLed(0,6,5,1);
lc.setLed(0,6,6,0);
lc.setLed(0,6,7,0);

}
