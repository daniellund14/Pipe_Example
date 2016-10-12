#ifndef NUMBERS_INCLUDE
#define NUMBERS_INCLUDE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Numbers{
   //As per P2 documentation files will only contain 10 doubles
   double numbers[10];
   char *fileName;
   int size;
   double mode;
   double median;
   double mean;
   double max;
   double min;
}Numbers;
int readFile(Numbers *numbers);
int getSize(Numbers *numbers);
void printNumbers(Numbers *numbers);
void calculateMode(Numbers *numbers);
void calculateMean(Numbers *numbers);
void calculateMedian(Numbers *numbers);
void calcMedian(Numbers *numbers);
#endif //NUMBERS_INCLUDE
