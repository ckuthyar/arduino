int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // array to store the segment pins
int digitPins[] = {9}; // array to store the digit pins
int numPins = 7; // number of segment pins in the array
int digitNum = 1; // number of digits in the display

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(segmentPins[i], OUTPUT); // set all the segment pins as outputs
  }
  for (int i = 0; i < digitNum; i++) {
    pinMode(digitPins[i], OUTPUT); // set all the digit pins as outputs
  }
}

void loop() {
  displayNumber(1); // display the number 1 on the display
  delay(5000); // wait for 5 seconds before displaying the next number
}

void displayNumber(int num) {
  byte numbers[] = { // array to store the binary values of each number
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B10111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11110110 // 9
  };
  
  byte displayNum = numbers[num]; // get the binary value of the input number
  
  // turn on the digit
  digitalWrite(digitPins[0], HIGH);
  
  // write the binary value of each segment pin for the selected digit
  for (int i = 0; i < numPins; i++) {
    digitalWrite(segmentPins[i], bitRead(displayNum, i)); // write the binary value of each segment pin
  }
}
