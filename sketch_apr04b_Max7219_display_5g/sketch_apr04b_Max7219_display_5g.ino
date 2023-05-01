//Mario's Ideas
//MAX7219 - using Led Control library to display all   leds one by one
#include <LedControl.h>
int DIN = 11;
int CS = 10;
int   CLK = 13; 
LedControl lc=LedControl(DIN, CLK, CS,0);

String fun1;
char digits[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int binary[64]={
  0,0,0,0,
  0,0,0,1,
  0,0,1,0,
  0,0,1,1,
  0,1,0,0,
  0,1,0,1,
  0,1,1,0,
  0,1,1,1,
  1,0,0,0,
  1,0,0,1,
  1,0,1,0,
  1,0,1,1,
  1,1,0,0,
  1,1,0,1,
  1,1,1,0,
  1,1,1,1};
int position=0;
int rowcols[8][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
  };
String funnel;;
String part1;
char char1;
int row=0;
int offset=2;
String zero="001C222222221C00";
String one="0010101010101000";
String two="003E040810203E00";
String three="003E0408043E0000";
String four="00202020243E0400";
String five="003E203C02023C00";
String six="001C2020202C1C00";
String seven="003C040404040400";
String eight="0018242418182418";
String nine="001C221E02020200";
String parallel1="FF7E3C18183C7EFF";


String list1[10]={zero,one,two,three,four,five,six,seven,eight,nine};

void setup()   {
Serial.begin(9600);
lc.shutdown(0,false);
lc.setIntensity(0,0);
lc.clearDisplay(0);  
}

void   loop() {
  for(int i=0;i<sizeof(list1);i++){
    funnel=list1[i];
    displayfunnel();
    delay(3000);
    lc.clearDisplay(0);
  } 
}

void displayfunnel(){
for(row=0;row<8;row++){
  fun1=funnel.substring(row*2,row*2+offset);
  char1=fun1[0];
  for(int i=0;i<16;i++){
    if(char1==digits[i]){
      rowcols[row][0]=binary[(i)*4 + 0];
      rowcols[row][1]=binary[(i)*4 + 1];
      rowcols[row][2]=binary[(i)*4 + 2];
      rowcols[row][3]=binary[(i)*4 + 3];      
      }
  }
  char1=fun1[1];
  for(int i=0;i<16;i++){
    if(char1==digits[i]){
      rowcols[row][4]=binary[(i)*4 + 0];
      rowcols[row][5]=binary[(i)*4 + 1];
      rowcols[row][6]=binary[(i)*4 + 2];
      rowcols[row][7]=binary[(i)*4 + 3];  
    }
  }
}

for(int j=0; j<8; j++){
  for(int i=0; i<8; i++){
    if(rowcols[j][i]==1){
     lc.setLed(0,j,i,1);
     }
  }
}  
}


 
