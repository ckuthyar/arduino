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

line1();
delay(1000);
lc.clearDisplay(0);


} 



void line1(){

lc.setLed(2,7,0,true);
lc.setLed(2,7,1,true);
lc.setLed(2,7,2,true);
lc.setLed(2,7,3,true);
lc.setLed(2,7,4,true);
lc.setLed(2,7,5,true);
lc.setLed(2,7,6,true);
lc.setLed(2,7,7,true);
delay(1000);
lc.clearDisplay(0);

lc.setLed(1,7,0,true);
lc.setLed(1,7,1,true);
lc.setLed(1,7,2,true);
lc.setLed(1,7,3,true);
lc.setLed(1,7,4,true);
lc.setLed(1,7,5,true);
lc.setLed(1,7,6,true);
lc.setLed(1,7,7,true);
delay(1000);
lc.clearDisplay(0);

lc.setLed(0,7,0,true);
lc.setLed(0,7,1,true);
lc.setLed(0,7,2,true);
lc.setLed(0,7,3,false);
lc.setLed(0,4,4,true);
lc.setLed(0,7,5,true);
lc.setLed(0,7,6,true);
lc.setLed(0,7,7,true);

delay(1000);
lc.clearDisplay(0);
}
