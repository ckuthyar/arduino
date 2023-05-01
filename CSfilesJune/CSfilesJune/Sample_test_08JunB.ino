#include <LedControlSS.h>
#define NBR_MTX 10

#define s1cdnm 10                   // SangamOne Connected Display Number of Modules
#define s1cdncol s1cdnm*8           // SangamOne Connected Display Number of Columns
#define s1mxchinmsg 90              // SangamOne Connected Display Max number of characters in a message (accomodate about 90 char string)
/*
int s1cdnm = 10;                    // SangamOne Connected Display Number of Modules
int s1cdncol = s1cdnm*8;            // SangamOne Connected Display Number of Columns
*/

static int number=0;
int pos=0,k=0,Counter=0,passcount=0,msgcount=0,i=0,j=0,n=0,pass=0;
char ch;

LedControl lc=LedControl(12,11,10,NBR_MTX);

// String characters= "ABCDE 12345 A1B2C A2B3C A4B5C A5B6C ";
//char characters[]= "Welcome to ABC we are located at South Bangalore Karnataka INDIA Phone 91 80 23456789";
char characters[] = "Aa";
char characters1[]= "Bb12";
char characters2[]= "CcDd34";
char characters3[]= "EeFfGg56";
char characters4[]= "VWXYZ56789";
char characters5[]= "abcde";
char characters6[]= "fghijk";
char characters7[]= "lmnop";
char characters8[]= "qrstu";
char characters9[]= "NHSBSVNG";
char charactersA[]= "BSVNGUDI";

char msgstrlib1[]= "Welcome to ABC : we are located at South Bangalore: Karnataka: INDIA: Phone 91-80-23456789";
char msgstrlib2[]= "We offer the following services A1: A2: A3: A4: A5";
char msgstrlib3[]= "We offer the following services B1: B2: B3: B4: B5";
char msgstrlib4[]= "We offer the following services C1: C2: C3: C4: C5";
char msgstrlib5[]= "We offer the following services D1: D2: D3: D4: D5";
char msgstrlib6[]= "We offer the following services E1: E2: E3: E4: E5";
char msgstrlib7[]= "We offer the following services F1: F2: F3: F4: F5";
char msgstrlib8[]= "We offer the following services G1: G2: G3: G4: G5";
char msgstrlib9[]= "Powered by SangamOne Connected Services p1 Powered by SangamOne Connected Services p2 ";
char msgstrlib0[]= "A1B2C3D4E5F6G7H8I9JKLMNOPQR1S2T3U4V5W6X7Y8Z9 a1b2c3d4e5f6g7h8i9jklmnopqr1s2t3u4v5w6x7y8z9";
/*
String limiters= "123456789a123456789b123456789c123456789d123456789e123456789f123456789g123456789h123456789i"
*/
char *msgstrcur; // this is a pointer to the currently active one from the message string library

int s1cdmsgnu=1;// SangamOne Connected Display message number, it identifies the number which is currently active from the message string library 
int src_img_byt_cnt=0; //Total number of bytes in the image generated

byte array_src[s1mxchinmsg*6]={0};  // accommodate about 90 char string

byte array_dsply[s1cdncol]={0};     // 80 when 10 modules are cascaded


void setup() {
  
  Serial.begin (9600);
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false);
    lc.setIntensity(i,0);
  }
}
//void chngstring(int msgcount)
//ChangeString program has been retired on 08Jun2014 by CS

void s1pgm_genimg()
  {
//     char ch= msgstrlib[Counter];
     switch(s1cdmsgnu)
     {
     case 1:
      msgstrcur = &msgstrlib1[0];
      break;
 /*
     case 2:
      msgstrcur = &msgstrlib2;
      break;
     case 3:
      msgstrcur = &msgstrlib3;
      break;
     case 4:
      msgstrcur = &msgstrlib4;
      break;
     case 5:
      msgstrcur = &msgstrlib5;
      break;
     case 6:
      msgstrcur = &msgstrlib6;
      break;
     case 7:
      msgstrcur = &msgstrlib7;
      break;
     case 8:
      msgstrcur = &msgstrlib8;
      break;
 */
     case 9:
      msgstrcur = &msgstrlib9[0];
      break;
     default:
      msgstrcur = &msgstrlib0[0];
    }  
//     char ch= msgstrlib[Counter];

    for(Counter=0;Counter<=90;Counter++)
    {
     pos=lc.getCharArrayPosition(*msgstrcur+Counter);   // one of these should work, I don't know which one for now
     pos=lc.getCharArrayPosition(*(msgstrcur+Counter)); // one of these should work, I don't know which one for now

     for(int i=0;i<=5;i++)
      {
       array_src[k]=alphabetBitmap[pos][i];
       k++;
      }
    }
    src_img_byt_cnt=k;  
  }


// Code section above tested  by RamaRao on April ??th 2014
// ***** End of section above *****

     

   

void loop()
{
// Code created by RamaRao on April 7th 2014 (Start)
//
// ***** Section Begins below *****
// Code section below tested  by RamaRao on April 12th 2014
//
// All existing lc.setrow pieces of code can be removed by inserting the repeated for loop structure below 
//
/*
int s1cdnm = 10; // SangamOne Connected Display Number of Modules
int s1cdncol = s1cdnm*8; //  SangamOne Connected Display Number of Columns
*/
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

// Code section above tested  by RamaRao on April 12th 2014
// ***** Section Ends above *****

  
     
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
      if(passcount==0)
    {
      //chngstring(msgcount); 
      s1pgm_genimg();
      
    }
      
      if(passcount<541)
    {
        passcount++;
    }
      if(passcount>540)
    {
      msgcount++;
      if(msgcount>=4)
      {
    msgcount=0;
      }
      passcount=0;    
    }
    

    delay(10);
  
}


