#include <LedControlSS.h>
#define NBR_MTX 10

#define s1cdnm 10                   // SangamOne Connected Display Number of Modules
#define s1cdncol s1cdnm*8           // SangamOne Connected Display Number of Columns
#define s1mxchinmsg 90              // SangamOne Connected Display Max number of characters in a message (accomodate about 90 char string)
/*
int s1cdnm = 10;                    // SangamOne Connected Display Number of Modules
int s1cdncol = s1cdnm*8;            // SangamOne Connected Display Number of Columns
*/

//static int number=0;
//int pos=0,k=0,Counter=0,passcount=0,msgcount=0,i=0,j=0,n=0,pass=0;
//char ch;

LedControl lc=LedControl(12,11,10,NBR_MTX);

char msgstrlib1[] = "Welcome to ABC : we are located at South Bangalore: Karnataka: INDIA: Phone 91-80-23456789";
char msgstrlib2[] = "Two Three Four Five Six";
char msgstrlib3[] = "Three Four Five Six Seven";
char msgstrlib4[] = "Four Five Six Seven Eight";
char msgstrlib5[] = "Five Six Seven Eight Nine";
char msgstrlib6[] = "Six Seven Eight Nine Ten";
char msgstrlib7[] = "Seven Eight Nine Ten Zero";
char msgstrlib8[] = "Eight Nine Ten Zero One";
char msgstrlib9[] = "Powered by SangamOne Connected Services";
char msgstrlib0[] = "A1B2C3D4E5F6G7H8I9JKLMNOPQR1S2T3U4V5W6X7Y8Z9 a1b2c3d4e5f6g7h8i9jklmnopqr1s2t3u4v5w6x7y8z9";
/*
String limiters[] = "123456789a123456789b123456789c123456789d123456789e123456789f123456789g123456789h123456789i"
*/
char *msgstrcur; // this is a pointer to the currently active one from the message string library
int msgstrlen;   // this is the length of currently active message string picked from the library

int s1cdmsgnu=1;// SangamOne Connected Display message number, it identifies the number which is currently active from the message string library 
int src_img_byt_cnt=0; //Total number of bytes in the image generated

int passcount=0, j=0, i=0;

byte array_src[s1mxchinmsg*6]={0};  // accommodate about 90 char string

byte array_dsply[s1cdncol]={0};     // 80 when 10 modules are cascaded


void setup() 
{
  Serial.begin (9600);
  for (int i=0; i< NBR_MTX; i++)
  {
    lc.shutdown(i,false);
    lc.setIntensity(i,0);
  }
}


// Code created by RamaRao on April 7th 2014 (Start)
//
// ***** Section Begins below *****
// Code section below tested  by CS on June ??th 2014
//
// Code segment to generate image for one of multiple messages considered for scrolling.
// The display messages are numbered from 1 to 9
// The message 1 and 9 are fixed
// The message 0 is for test purpose
// The message 2 to 8 are programmable for clients specific requirements
// Each message can be a max of 90 characters long
//

void s1pgm_genimg()
  {
     int k, pos, Counter;
     switch(s1cdmsgnu)
     {
     case 1:
      msgstrcur = &msgstrlib1[0];
      msgstrlen = sizeof (msgstrlib1);
      break; 
     case 2:
      msgstrcur = &msgstrlib2[0];
      msgstrlen = sizeof (msgstrlib2);
      break;
     case 3:
      msgstrcur = &msgstrlib3[0];
      msgstrlen = sizeof (msgstrlib3);
      break;
     case 4:
      msgstrcur = &msgstrlib4[0];
      msgstrlen = sizeof (msgstrlib4);
      break;
     case 5:
      msgstrcur = &msgstrlib5[0];
      msgstrlen = sizeof (msgstrlib5);
      break;
     case 6:
      msgstrcur = &msgstrlib6[0];
      msgstrlen = sizeof (msgstrlib6);
      break;
     case 7:
      msgstrcur = &msgstrlib7[0];
      msgstrlen = sizeof (msgstrlib7);
      break;
     case 8:
      msgstrcur = &msgstrlib8[0];
      msgstrlen = sizeof (msgstrlib8);
      break;
     case 9:
      msgstrcur = &msgstrlib9[0];
      msgstrlen = sizeof (msgstrlib9);
      break;
     default:
      msgstrcur = &msgstrlib0[0];
      msgstrlen = sizeof (msgstrlib0);
    }

    if(msgstrlen>s1mxchinmsg)             // is the string too large ?
       msgstrlen=s1mxchinmsg;             // limit it the extent we can process
    k=0;
    for(Counter=0;Counter<msgstrlen;Counter++)
    //for(Counter=0;Counter<=19;Counter++)               // for debug purposes, we will restrict to 20 characters
    {
    pos=lc.getCharArrayPosition(*(msgstrcur+Counter)); // one of these should work, I don't know which one for now

     for(int i=0;i<=5;i++)
      {
       array_src[k]=alphabetBitmap[pos][i];
       k++;
      }
    }
    k--;  //At the end of the For loop, the value of k has got incremented. This is being restored.
    src_img_byt_cnt=k;  
  }

// caveat hardcoding for debug purpose yet to be dropped - pending CS
// Code section above tested  by CS on June ??th 2014
// ***** Section Ends above *****

     

   

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


// Code created by RamaRao on June 12th 2014 (Start)
//
// ***** Section Begins below *****
// Code section below tested  by CS on June ??th 2014
//
// Code segment to move data required for scrolling
// Code segment to move data of relevance from source array to image array, as source size (540) is greater than image size (80)
//
if(passcount)
{
    j=passcount;
    i=0;
    if(j<s1cdncol)
    {
      do

      {
      j--;
      array_dsply[i]=array_src[j];
      //array_src[j]=0;
      i++;
      }while(j>0); // update of array when bytes are less than # of columns
    }
    else
    {
      do

      {
      j--;
      if(j>src_img_byt_cnt)
         array_dsply[i]=0;
      else
         array_dsply[i]=array_src[j];
      //array_src[j]=0;
      i++;
      }while(i<s1cdncol);  // update of array when bytes that can be displayed is only as much as the # of columns
    } 
}

//
// Code section above tested  by CS on June ??th 2014
// ***** Section Ends above *****


      if(passcount==0)
    {
      s1pgm_genimg();
    }
      if(passcount<(src_img_byt_cnt + s1cdncol + 3))
    {
        passcount++;
    }
      if(passcount>(src_img_byt_cnt + s1cdncol + 2))
   //the upper limited is defined by the sum of 90*6 + number of LED columns
   //the additional number of LED columns is required so that the display cascades from right to left completely
    {
      passcount=0;
      s1cdmsgnu++;
      if(s1cdmsgnu>10)
      s1cdmsgnu=1;
    }
    

    //delay(10);
    //delay(20);
    //delay(50);
    //delay(100);
    //delay(200);
    //delay(500);
    //delay(1000);
  
}

