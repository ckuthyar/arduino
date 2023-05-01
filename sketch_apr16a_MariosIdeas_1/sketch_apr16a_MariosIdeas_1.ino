// Mario's Ideas
//MAX7219 - using Led Control library to scroll the  sample text
#include <LedControl.h>

int DIN = 11;
int CS = 10;
int  CLK = 13;
LedControl lc=LedControl(DIN, CLK, CS,0);

int position=0;

int  Marios_ideas [8] [54] ={
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0},
  {0,1,1,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0},
  {0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0, 1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0}
  };


void setup() {

   lc.shutdown(0,false);
   lc.setIntensity(0,0);
   lc.clearDisplay(0);
}

void loop() {
  for (int j=0;j<8;j++){
    for (int i=0;i<8;i++){
    lc.setLed(0,i,j,Marios_ideas[j][(i+position)-abs((i+position)/54)*54]);
    }
  }
  delay(2000);
  position=position+1;
}  
