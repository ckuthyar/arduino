/**
 * @file Led-matrix-counting.ino
 * @author Noa Sakurajin (noasakurajin@web.de)
 * @brief counting up on an led matrix
 * @version 0.1
 * @date 2020-12-30
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "LedController.hpp"

// the pin where the chip select is connected to
#define CS 10

#define Segments 4 // assuming 4 segments for 4x8x8 LED matrix

#define delayTime 200 // Delay between Frames

LedController<Segments, 1> lc;

void setup()
{
    // initialize LED matrix
    lc.init(CS);
}

void loop()
{
    // display pattern on the LED matrix
    // First row - all dots lit
    for (int row = 0; row < 8; row++) // assuming 8 rows
    {
        for (int col = 0; col < 32; col++) // assuming 8 columns
        {
            lc.setLed(row, 0, col, true); // segmentNumber = row, row = 0, col = col, state = true
        }
    }
    // second row 
 for (int row = 0; row < 8; row++) // assuming 8 rows
    {
        for (int col = 1; col < 31; col++) // assuming 8 columns
        {
            lc.setLed(row, 1, col, true); // segmentNumber = row, row = 0, col = col, state = true
        }
    }   

}
