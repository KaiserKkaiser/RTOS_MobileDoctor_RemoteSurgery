#include<stdio.h>
#include "tcb.h"

// the number of recording time; be int, count how many 0.5 sec has passed
int halfsec = 0;

// Time values, to determine whether to blink
unsigned long timef, timeb;


void shift(int newVal,int Bufsize,unsigned int* Buf) {
  for (int i = 1; i <= Bufsize-1; i++) { 
    //if ( (*Buff)[Bufsize - (i+1)] != null)
   // if ( Buf[Bufsize - (i+1)] != NULL) { //if element 6 is not null
      *(Buf + (Bufsize - i)) =  *(Buf + (Bufsize - (i+1)));  //element 7 = element 6
    }
    *Buf = newVal;
  //}
}

void shiftChar(int newVal,int Bufsize,unsigned char* Buf) {
  for (int i = 1; i <= Bufsize-1; i++) { 
    //if ( (*Buff)[Bufsize - (i+1)] != null)
   // if ( Buf[Bufsize - (i+1)] != NULL) { //if element 6 is not null
      *(Buf + (Bufsize - i)) =  *(Buf + (Bufsize - (i+1)));  //element 7 = element 6    //}
  }
    *Buf = newVal;
  
}


// TODO: fill in this helper function of whether value is high or low
bool isHigh() {
    return true;
}

// TODO: fill in this helper function of whether value is out of range 5%
bool isOutOfRange() {
    return true;
}

/*
*    @param: int index, TCB* taskQ;
*    pre: index < length(taskQ);
*    helper method of sechdule function;
*    April 23, 2019 by Kaiser Sun
*/
void run(TCB* taskQ) {
    // Call the function in the taskQ;
    (*taskQ->myTask)(taskQ->taskDataPtr);
}

/*
*    @para: take in x, y, the center of the rectangle
*           bool d, to see whether it is unselected
*    Draw the buttons
*    (700, 250) -> T
*    (700, 500) -> BP
*    (700, 750) -> PR
*/
void drawSub(int x, int y, bool d) {
    Serial.print("Entered drawSub");
    if(!d) {
        tft.fillRect(x, y, 260, 80, RED);
    } else {
        tft.fillRect(x, y, 260, 80, GREEN);
    }
    // See Line595 of Elegoo_GFX.cpp
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(x + 10, y + 10);
    if(y == 0) {
        tft.print("BloodPressure");
    } else if(y == 80) {
        tft.print("PulseRate");
    } else if(y == 160) {
        tft.print("Temperature");
    }
}