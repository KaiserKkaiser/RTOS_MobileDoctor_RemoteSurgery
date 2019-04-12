#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void f1Data(int* delay1);
void f2Clear(int* delay2);
int printab = 0, printcd = 0;
    // 0 stand for did not print, 1 stand for printed;
    // if printed, then we clear the screen;
int time1, time2;
int main(void) {
    // Define the pointers
    int* time1Ptr = &time1;
    int* time2Ptr = &time2;
    //  prompt for data
	printf("Please enter a single digit between 0-9 \n");
	//  get the data
	scanf("%d%d", &time1, &time2);
    int times = *time2Ptr/(*time1Ptr);
    while(1) {
		for(int i = 0; i < times; i ++) {
			f1Data(time1Ptr);
		}
		if(printcd == 0) {
        system("clear");
        printf("B D\n");
        printcd = 1;
        } else {
        system("clear");
        printcd = 0;
        }
	}
	return 0;
}

// pre: take in a pointer of int delay1
void f1Data(int* delay1){
    f2Clear(delay1);
	if(printab == 0) {
          system("clear");
          printf("A C\n");
          printab = 1;
        } else {
          system("clear");
          printab = 0;
    }
	if(printcd == 1) {
          printf("B D\n");
    }
}

// pre: take in a pointer of int delay2
void f2Clear(int* delay2) {
    // sleep for the value of the pointer time
    sleep(*delay2);
	system("clear");
}