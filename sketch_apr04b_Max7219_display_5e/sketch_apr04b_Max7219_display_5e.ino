//Mario's Ideas
//MAX7219 - using Led Control library to display all   leds one by one
#include <LedControl.h>

int DIN = 11;
int CS = 10;
int   CLK = 13; 
LedControl lc=LedControl(DIN, CLK, CS,0);

char digits[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
String binary[16]={"0000","0001","0010","0011","0100","0101", "0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
int position=0;
String result1;
int result2=0;
int rowcols[8][8];
String five= "003E203C02023C00";
String part1;
String five1=five.substring(0,2);
String five2=five.substring(2,4);

char five10=(char)five1[0];
char five11=(char)five1[1];
void setup()   {
Serial.begin(9600);
lc.shutdown(0,false);
lc.setIntensity(0,0);
lc.clearDisplay(0);  
}

void   loop() {
displayfive();
delay(1000);
//lc.setLed(0,4,5,true);

}

void displayfive(){
  
  part1=five.substring(0,2);
  //Serial.println(part1);
  show1(part1[0], part1[1],0);

  part1=five.substring(2,4);
  //Serial.println(part1);
  show1(part1[0], part1[1],1);

  //part1=five.substring(4,6);
  //Serial.println(part1);
  //show1(part1[0], part1[1],1);

  //part1=five.substring(6,8);
  //Serial.println(part1);
  //show1(part1[0], part1[1],1);

  //part1=five.substring(8,10);
  //Serial.println(part1);
  //show1(part1[0], part1[1],1);

  //part1=five.substring(10,12);
  //Serial.println(part1);
  //show1(part1[0], part1[1],1);

  //part1=five.substring(12,14);
  //Serial.println(part1);
  //show1(part1[0], part1[1],1);

  //part1=five.substring(14,16);
  //Serial.println(part1);
  //show1(part1[0], part1[1],1);
  Serial.print("%%%%%%%%%%%%%");

  Serial.print(rowcols[1][0]);
  Serial.print(rowcols[1][1]);
  Serial.print(rowcols[1][2]);
  Serial.print(rowcols[1][3]);
  Serial.print(rowcols[1][4]);
  Serial.print(rowcols[1][5]);
  Serial.print(rowcols[1][6]);
  Serial.print(rowcols[1][7]);
  Serial.print("%%%%%%%%%%%%%%");
  
  rowcols[1][0]=0;
  rowcols[1][1]=0;
  rowcols[1][2]=1;
  rowcols[1][3]=1;
  rowcols[1][4]=1;
  rowcols[1][5]=1;
  rowcols[1][6]=1;
  rowcols[1][7]=0;
  
  rowcols[2][0]=0;
  rowcols[2][1]=0;
  rowcols[2][2]=1;
  rowcols[2][3]=0;
  rowcols[2][4]=0;
  rowcols[2][5]=0;
  rowcols[2][6]=0;
  rowcols[2][7]=0;
  
  rowcols[3][0]=0;
  rowcols[3][1]=0;
  rowcols[3][2]=1;
  rowcols[3][3]=1;
  rowcols[3][4]=1;
  rowcols[3][5]=1;
  rowcols[3][6]=0;
  rowcols[3][7]=0;
  
  rowcols[4][0]=0;
  rowcols[4][1]=0;
  rowcols[4][2]=0;
  rowcols[4][3]=0;
  rowcols[4][4]=0;
  rowcols[4][5]=0;
  rowcols[4][6]=1;
  rowcols[4][7]=0;
  
  rowcols[5][0]=0;
  rowcols[5][1]=0;
  rowcols[5][2]=0;
  rowcols[5][3]=0;
  rowcols[5][4]=0;
  rowcols[5][5]=0;
  rowcols[5][6]=1;
  rowcols[5][7]=0;
  
  rowcols[6][0]=0;
  rowcols[6][1]=0;
  rowcols[6][2]=1;
  rowcols[6][3]=1;
  rowcols[6][4]=1;
  rowcols[6][5]=1;
  rowcols[6][6]=0;
  rowcols[6][7]=0;
  
  rowcols[7][0]=0;
  rowcols[7][1]=0;
  rowcols[7][2]=0;
  rowcols[7][3]=0;
  rowcols[7][4]=0;
  rowcols[7][5]=0;
  rowcols[7][6]=0;
  rowcols[7][7]=0;
   
  
  for(int j=0; j<8; j++){
    for(int i=0; i<8; i++){
     
      if(rowcols[j][i]==1){
       lc.setLed(0,j,i,1);
       }
    }
  }

}


//Function definition begins
void show1(char in1, char in2, int row){

  for(int i=0; i<16; i++){
  if(digits[i]==in1){
    position=i;
    break;
    }
  }
  result1=binary[position];
  Serial.println("Hello before");
  Serial.println(result1);
  Serial.println("Hello after");

  if(result1[0]=="1"){
    rowcols[row][0]=1;
  }
  else{
    rowcols[row][0]=0;
  }
  if(result1[1]=="1"){
    rowcols[row][1]=1;
  }
   else{
    rowcols[row][0]=0;
  }
  if(result1[2]=="1"){
    rowcols[row][2]=1;
  }
   else{
    rowcols[row][0]=0;
  }
  if(result1[3]=="1"){
    rowcols[row][3]=1;
  }
   else{
    rowcols[row][0]=0;
  }

  

  

  Serial.println("...........");
  Serial.print("row ");
  Serial.println(row);
  Serial.print(result1[0]);
  Serial.print(result1[1]);
  Serial.print(result1[2]);
  Serial.print(result1[3]);

  
  Serial.println("..........");

  Serial.println("@@@@@@@@@@@");
  Serial.print(rowcols[1][0]);
  Serial.print(rowcols[1][1]);
  Serial.print(rowcols[1][2]);
  Serial.print(rowcols[1][3]);
  Serial.println("@@@@@@@@@@@");





 

  for(int i=0; i<16; i++){
  if(digits[i]==in2){
    position=i;
    break;
    }
  }
  result1=binary[position];


  if(result1[4]=="1"){
    rowcols[row][4]=1;
  }
   else{
    rowcols[row][0]=0;
  }
  if(result1[5]=="1"){
    rowcols[row][5]=1;
  }
   else{
    rowcols[row][0]=0;
  }
  if(result1[6]=="1"){
    rowcols[row][6]=1;
  }
   else{
    rowcols[row][0]=0;
  }
  if(result1[7]=="1"){
    rowcols[row][7]=1;
  }
   else{
    rowcols[row][0]=0;
  }
  Serial.print("row ");
  Serial.println(row);

  Serial.print(rowcols[1][4]);
  Serial.print(rowcols[1][5]);
  Serial.print(rowcols[1][6]);
  Serial.print(rowcols[1][7]);
  Serial.println("@@@@@@@@@@@");

  
 

  //Serial.println(rowcols[0][0]);
}
