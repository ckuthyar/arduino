#include <LedControlSS.h>
#define NBR_MTX 10

static int number=0;
int pos=0,k=0,Counter=0,passcount=0,msgcount=0,i=0,j=0,n=0,pass=0;
char ch;

LedControl lc=LedControl(12,11,10,NBR_MTX);

// String characters= "ABCDE 12345 A1B2C A2B3C A4B5C A5B6C ";
//char characters[]= "Welcome to ABC we are located at South Bangalore Karnataka INDIA Phone 91 80 23456789";
char characters[] = "ABCDE12345";
char characters9[]= "NHSBSVNG";
char charactersA[]= "BSVNGUDI";
char characters1[]= "FGHIJ23456";
char characters2[]= "KLMNO34567";
char characters3[]= "PQRSTU45678";
char characters4[]= "VWXYZ56789";
char characters5[]= "abcde";
char characters6[]= "fghijk";
char characters7[]= "lmnop";
char characters8[]= "qrstu";

byte array_src[540]={0}; 

byte array_dsply[96]=
{

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void setup() {
  
  Serial.begin (9600);
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false);
    lc.setIntensity(i,0);
  }
  
  int pos=0,k=0;
  
  for(Counter=0;Counter<=85;Counter++)
  {
    char ch= characters[Counter];
    Serial.println(ch);
    Serial.println(Counter);
    pos=lc.getCharArrayPosition(ch);
    for(int i=0;i<=5;i++)
      {
        array_src[k]=alphabetBitmap[pos][i];
        k++;
      }
  
  }
  
}


void chngstring(int msgcount)
{
// Serial.println(msgcount);
 if(msgcount>4){
    msgcount=0;
  }
   byte array_src[510]={0};
       k=0;
   if(msgcount==0){
    for(Counter=0;Counter<=10;Counter++)   //for testing, we are keeping only first 10 characters. Should be made 85 later on. Ideally, the length should be dynamically picked up.
    {
       ch=characters[Counter];
       pos=lc.getCharArrayPosition(ch);
       for(int i=0;i<=5;i++)
       {
          array_src[k]=alphabetBitmap[pos][i];
          k++;
      } 
    }
    }
   if(msgcount==1){
    for(Counter=0;Counter<=10;Counter++)   //for testing, we are keeping only first 10 characters. Should be made 85 later on. Ideally, the length should be dynamically picked up.
    {
       ch=characters1[Counter];
       pos=lc.getCharArrayPosition(ch);
       Serial.println(pos);
       for(int i=0;i<=5;i++)
       {
          array_src[k]=alphabetBitmap[pos][i];
          k++;
      } 
    }
    }
    if(msgcount==2){
    for(Counter=0;Counter<=10;Counter++)   //for testing, we are keeping only first 10 characters. Should be made 85 later on. Ideally, the length should be dynamically picked up.
    {
       ch=characters2[Counter];
       pos=lc.getCharArrayPosition(ch);
       for(int i=0;i<=5;i++)
       {
          array_src[k]=alphabetBitmap[pos][i];
          k++;
       } 
    }
    } 
    if(msgcount==3){
    for(Counter=0;Counter<=10;Counter++)   //for testing, we are keeping only first 10 characters. Should be made 85 later on. Ideally, the length should be dynamically picked up.
    {
       ch=characters8[Counter];
       ch=characters7[Counter];
       ch=characters6[Counter];
       ch=characters5[Counter];
       ch=characters4[Counter];
       ch=characters3[Counter];
       pos=lc.getCharArrayPosition(ch);
       for(int i=0;i<=5;i++)
       {
          array_src[k]=alphabetBitmap[pos][i];
          k++;
      } 
    }
    }
     
/*    pos=lc.getCharArrayPosition(ch);
    for(int i=0;i<=5;i++)
      {
        array_src[k]=alphabetBitmap[pos][i];
        k++;
      } */
  }
   
//   }

void loop()
{
   //chngstring(number);
// Code created by RamaRao on April 7th 2013 (Start)
//
// ***** Begining for new section below *****
//
// All existing lc.setrow pieces of code can be removed by inserting the repeated for loop structure below 
//

int s1cdnm = NBR_MTX; // SangamOne Connected Display Number of Modules
int s1cdncol = s1cdnm*8; //  SangamOne Connected Display Number of Columns

int s1index_i=0; // can be commented out as it is initialised in the for loop
int s1index_j=0; // can be commented out as it is initialised in the for loop
int s1index_k=0;

    for(s1index_i=0;s1index_i<s1cdnm;s1index_i++)
    {
       for(s1index_j=7;s1index_j>=0;s1index_j--)
       {
        lc.setRow(s1index_i,s1index_j,array_dsply[s1index_k]);
        s1index_k++;
       }
    }
    

// ***** End of section above *****

  
/*    if(passcount>540)
    {
    passcount=1;
    number++;
    chngstring(number); 
    }
    j=passcount;
    i=0;
 */ 
  
      if(passcount>540) 
    {
//      Serial.println(passcount);
     // byte array_src[540]={0};
     // Serial.flush();
      //lc.clearAll();
      msgcount++;
      
      chngstring(msgcount);
      passcount=1;
      
      
    }
    
    Serial.println(msgcount);
    Serial.println(passcount);
    j=passcount;
    i=0;
      if(j<s1cdncol) 
    {
     do

     {
     j--;
     array_dsply[i]=array_src[j];
     i++;
     }while(j>0); // update of array when bytes are less than # of columns
    } 
    else
    {
     do

     {
     j--;
     array_dsply[i]=array_src[j];
     i++;
     }while(i<s1cdncol);  // update of array when bytes that can be displayed is only as much as the # of columns
    } 
    
    

    passcount++;
//    msgcount++;
    delay(10);
  
}

