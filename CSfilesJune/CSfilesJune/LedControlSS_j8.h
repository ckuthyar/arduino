/*
 *    LedControl.h - A library for controling Leds with a MAX7219/MAX7221
 *    Copyright (c) 2007 Eberhard Fahle
 * 
 *    Permission is hereby granted, free of charge, to any person
 *    obtaining a copy of this software and associated documentation
 *    files (the "Software"), to deal in the Software without
 *    restriction, including without limitation the rights to use,
 *    copy, modify, merge, publish, distribute, sublicense, and/or sell
 *    copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following
 *    conditions:
 * 
 *    This permission notice shall be included in all copies or 
 *    substantial portions of the Software.
 * 
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *    OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef LedControl_h
#define LedControl_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#include <stdio.h>
#else
#include <WProgram.h>
#endif

/*
 * Segments to be switched on for characters and digits on
 * 7-Segment Displays
 */
const static byte charTable[128] = {
    B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,
    B01111111,B01111011,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B10000000,B00000001,B10000000,B00000000,
    B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,
    B01111111,B01111011,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,B00000000,
    B00110111,B00000000,B00000000,B00000000,B00001110,B00000000,B00000000,B00000000,
    B01100111,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001000,
    B00000000,B01110111,B00011111,B00001101,B00111101,B01001111,B01000111,B00000000,
    B00110111,B00000000,B00000000,B00000000,B00001110,B00000000,B00000000,B00000000,
    B01100111,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
    B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000
};


const static byte alphabetBitmap[67][6] = 
{                                                // Bit map array begins
{0x7E, 0x81, 0x81, 0x81, 0x7E, 0x00}, //0
{0x04, 0x82, 0xFF, 0x80, 0x00, 0x00}, //1
{0xE2, 0x91, 0x91, 0x91, 0x8E, 0x00}, //2
{0x42, 0x89, 0x89, 0x89, 0x76, 0x00}, //3
{0x1F, 0x10, 0x10, 0xFF, 0x10, 0x00}, //4
{0x8F, 0x89, 0x89, 0x89, 0x71, 0x00}, //5
{0x7E, 0x89, 0x89, 0x89, 0x71, 0x00}, //6
{0x01, 0x01, 0xF9, 0x05, 0x03, 0x00}, //7
{0x76, 0x89, 0x89, 0x89, 0x76, 0x00}, //8
{0x8E, 0x91, 0x91, 0x91, 0x7E, 0x00}, //9
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // blank space
{0x00, 0x00, 0x90, 0x00, 0x00, 0x00}, //:
{0x00, 0x10, 0x10, 0x10, 0x10, 0x00}, // -
{0x00, 0x00, 0x80, 0x00, 0x00, 0x00}, // .
{0xFC, 0x09, 0x11, 0x21, 0xFC, 0x00}, //Ñ
{0xFE, 0x11, 0x11, 0x11, 0xFE, 0x00}, //A
{0xFF, 0x89, 0x89, 0x89, 0x76, 0x00}, //B
{0x7E, 0x81, 0x81, 0x81, 0x42, 0x00}, //C
{0xFF, 0x81, 0x81, 0x81, 0x7E, 0x00}, //D
{0xFF, 0x89, 0x89, 0x89, 0x81, 0x00}, //E
{0xFF, 0x09, 0x09, 0x09, 0x01, 0x00}, //F
{0x7E, 0x81, 0x81, 0x91, 0x72, 0x00}, //G
{0xFF, 0x08, 0x08, 0x08, 0xFF, 0x00}, //H
{0x00, 0x81, 0xFF, 0x81, 0x00, 0x00}, //I
{0x60, 0x80, 0x80, 0x80, 0x7F, 0x00}, //J
{0xFF, 0x18, 0x24, 0x42, 0x81, 0x00}, //K
{0xFF, 0x80, 0x80, 0x80, 0x80, 0x00}, //L
{0xFF, 0x02, 0x04, 0x02, 0xFF, 0x00}, //M
{0xFF, 0x02, 0x04, 0x08, 0xFF, 0x00}, //N
{0x7E, 0x81, 0x81, 0x81, 0x7E, 0x00}, //O
{0xFF, 0x11, 0x11, 0x11, 0x0E, 0x00}, //P
{0x7E, 0x81, 0x81, 0xA1, 0x7E, 0x80}, //Q
{0xFF, 0x11, 0x31, 0x51, 0x8E, 0x00}, //R
{0x46, 0x89, 0x89, 0x89, 0x72, 0x00}, //S
{0x01, 0x01, 0xFF, 0x01, 0x01, 0x00}, //T
{0x7F, 0x80, 0x80, 0x80, 0x7F, 0x00}, //U
{0x3F, 0x40, 0x80, 0x40, 0x3F, 0x00}, //V
{0x7F, 0x80, 0x60, 0x80, 0x7F, 0x00}, //W
{0xE3, 0x14, 0x08, 0x14, 0xE3, 0x00}, //X
{0x03, 0x04, 0xF8, 0x04, 0x03, 0x00}, //Y
{0xE1, 0x91, 0x89, 0x85, 0x83, 0x00}, //Z
{0x60, 0x94, 0x94, 0x94, 0xF8, 0x00}, //  newa
{0xFF, 0x90, 0x88, 0x88, 0x70, 0x00}, //  newb
{0x78, 0x84, 0x84, 0x84, 0x48, 0x00}, //  newc
{0x70, 0x88, 0x88, 0x90, 0xFF, 0x00}, //  newd
{0x70, 0xA8, 0xA8, 0xA8, 0x30, 0x00}, //  newe
{0x10, 0xFE, 0x11, 0x01, 0x02, 0x00}, //  newf
{0x0C, 0x92, 0x92, 0x92, 0x7E, 0x00}, //  newg
{0xFF, 0x10, 0x08, 0x08, 0xF0, 0x00}, //  newh
{0x00, 0x00, 0xFA, 0x00, 0x00, 0x00}, //  newi
{0x40, 0x80, 0x84, 0x7D, 0x00, 0x00}, //  newj
{0xFF, 0x20, 0x50, 0x88, 0x00, 0x00}, //  newk
{0x00, 0x00, 0xFF, 0x80, 0x00, 0x00}, //  newl
{0xFC, 0x04, 0x18, 0x04, 0xF8, 0x00}, //  newm
{0xFC, 0x08, 0x04, 0x04, 0xF8, 0x00}, //  newn
{0x70, 0x88, 0x88, 0x88, 0x70, 0x00}, //  newo
{0xFC, 0x24, 0x24, 0x24, 0x18, 0x00}, //  newp
{0x18, 0x24, 0x24, 0x24, 0xFC, 0x00}, //  newq
{0xF8, 0x10, 0x08, 0x08, 0x10, 0x00}, //  newr
{0x90, 0xA8, 0xA8, 0xA8, 0x40, 0x00}, //  news
{0x04, 0x7F, 0x84, 0x80, 0x40, 0x00}, //  newt
{0x78, 0x80, 0x80, 0x40, 0xF8, 0x00}, //  newu
{0x38, 0x40, 0x80, 0x40, 0x38, 0x00}, //  newv
{0x78, 0x80, 0x70, 0x80, 0x78, 0x00}, //  neww
{0x88, 0x50, 0x20, 0x50, 0x88, 0x00}, //  newx
{0x00, 0x9C, 0xA0, 0xA0, 0x7C, 0x00}, //  newy
{0x88, 0xC8, 0xA8, 0x98, 0x88, 0x00}  //  newz
};                                               // Bit map array ends



class LedControl {
 private :
    /* The array for shifting the data to the devices */
    byte spidata[16];
    /* Send out a single command to the device */
    void spiTransfer(int addr, byte opcode, byte data);

	/* We keep track of the led-status for all 8 devices in this array */
//    byte status[64];
    byte status[80]; // modified by RR
     /* Data is shifted out of this pin*/
    int LEDCONTROL_SPI_MOSI;
    /* The clock is signaled on this pin */
    int LEDCONTROL_SPI_CLK;
    /* This one is driven LOW for chip selectzion */
    int LEDCONTROL_SPI_CS;
    /* The maximum number of devices we use */
    int maxDevices;
	
   
 public:
    /* 
     * Create a new controler 
     * Params :
     * dataPin		pin on the Arduino where data gets shifted out
     * clockPin		pin for the clock
     * csPin		pin for selecting the device 
     * numDevices	maximum number of devices that can be controled
     */
    LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);

    /*
     * Gets the number of devices attached to this LedControl.
     * Returns :
     * int	the number of devices on this LedControl
     */
    int getDeviceCount();

    /* 
     * Set the shutdown (power saving) mode for the device
     * Params :
     * addr	The address of the display to control
     * status	If true the device goes into power-down mode. Set to false
     *		for normal operation.
     */
    void shutdown(int addr, bool status);

    /* 
     * Set the number of digits (or rows) to be displayed.
     * See datasheet for sideeffects of the scanlimit on the brightness
     * of the display.
     * Params :
     * addr	address of the display to control
     * limit	number of digits to be displayed (1..8)
     */
    void setScanLimit(int addr, int limit);

    /* 
     * Set the brightness of the display.
     * Params:
     * addr		the address of the display to control
     * intensity	the brightness of the display. (0..15)
     */
    void setIntensity(int addr, int intensity);

    /* 
     * Switch all Leds on the display off. 
     * Params:
     * addr	address of the display to control
     */
    void clearDisplay(int addr);
	
    void clearAll();

    /* 
     * Set the status of a single Led.
     * Params :
     * addr	address of the display 
     * row	the row of the Led (0..7)
     * col	the column of the Led (0..7)
     * state	If true the led is switched on, 
     *		if false it is switched off
     */
    void setLed(int addr, int row, int col, boolean state);

    /* 
     * Set all 8 Led's in a row to a new state
     * Params:
     * addr	address of the display
     * row	row which is to be set (0..7)
     * value	each bit set to 1 will light up the
     *		corresponding Led.
     */
    void setRow(int addr, int row, byte value);

    /* 
     * Set all 8 Led's in a column to a new state
     * Params:
     * addr	address of the display
     * col	column which is to be set (0..7)
     * value	each bit set to 1 will light up the
     *		corresponding Led.
     */
    void setColumn(int addr, int col, byte value);

    /* 
     * Display a hexadecimal digit on a 7-Segment Display
     * Params:
     * addr	address of the display
     * digit	the position of the digit on the display (0..7)
     * value	the value to be displayed. (0x00..0x0F)
     * dp	sets the decimal point.
     */
    void setDigit(int addr, int digit, byte value, boolean dp);

    /* 
     * Display a character on a 7-Segment display.
     * There are only a few characters that make sense here :
     *	'0','1','2','3','4','5','6','7','8','9','0',
     *  'A','b','c','d','E','F','H','L','P',
     *  '.','-','_',' ' 
     * Params:
     * addr	address of the display
     * digit	the position of the character on the display (0..7)
     * value	the character to be displayed. 
     * dp	sets the decimal point.
     */
    void setChar(int addr, int digit, char value, boolean dp);
	
	//Returns the array number in the alphabetBitmap array 
	int getCharArrayPosition(char c);
	
	void writeString(int mtx, char * displayString);
    void displayChar(int matrix, int charIndex);
};

#endif	//LedControl.h



