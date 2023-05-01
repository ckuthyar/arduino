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
//lc.clearDisplay(0);00
one();
delay(1000);
lc.clearDisplay(0);

one2();
delay(1000);
lc.clearDisplay(0);



two();
delay(1000);
lc.clearDisplay(0);

three();
delay(1000);
lc.clearDisplay(0);

four();
delay(1000);
lc.clearDisplay(0);
}

void one(){
lc.setLed(0,1,3,true);
lc.setLed(0,2,3,true);
lc.setLed(0,3,3,true);
lc.setLed(0,4,3,true);
lc.setLed(0,5,3,true);
}
void one2(){
lc.setLed(1,1,3,true);
lc.setLed(1,2,3,true);
lc.setLed(1,3,3,true);
lc.setLed(1,4,3,true);
lc.setLed(1,5,3,true);
}

void two(){
lc.setLed(0,1,2,true);
lc.setLed(0,1,3,true);
lc.setLed(0,1,4,true);
lc.setLed(0,1,5,true);
lc.setLed(0,1,6,true);
lc.setLed(0,2,5,true);
lc.setLed(0,3,4,true);
lc.setLed(0,4,3,true);
lc.setLed(0,5,2,true);
lc.setLed(0,5,3,true);
lc.setLed(0,5,4,true);
lc.setLed(0,5,5,true);
lc.setLed(0,5,6,true);
}

void three(){
lc.setLed(0,1,2,true);
lc.setLed(0,1,3,true);
lc.setLed(0,1,4,true);
lc.setLed(0,1,5,true);
lc.setLed(0,1,6,true);
lc.setLed(0,2,5,true);
lc.setLed(0,3,4,true);
lc.setLed(0,4,5,true);
lc.setLed(0,5,6,true);
lc.setLed(0,5,5,true);
lc.setLed(0,5,4,true);
lc.setLed(0,5,3,true);
lc.setLed(0,5,2,true);
}

void four(){
lc.setLed(0,1,6,true);
lc.setLed(0,2,5,true);
lc.setLed(0,3,4,true);
lc.setLed(0,3,6,true);
lc.setLed(0,4,3,true);
lc.setLed(0,4,4,true);
lc.setLed(0,4,4,true);
lc.setLed(0,4,5,true);
lc.setLed(0,5,6,true);
lc.setLed(0,6,6,true);
}
