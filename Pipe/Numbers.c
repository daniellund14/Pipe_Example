#include <Numbers.h>

int readFile(Numbers *numbers){
    FILE *file;
   file = fopen(numbers->fileName, "r");
   if(!file){
      fprintf(stderr, "Error opening file\n");
      return -1;
   }else{
      numbers->size = 0;
      const size_t line_size = 300;
      char *line = malloc(line_size);
      char *token;
      //double numbers[10];
      int lineNumber = 0;
      int maxSet = 0;
      int minSet = 0;
      while(fgets(line, line_size, file)){
         if(strcmp(line, "\n") == 0){
            break;
         }
         token = strtok(line, "");
         double number = atof(token);
         numbers->numbers[lineNumber] = number;
         lineNumber++;
         if(number > numbers->max || !maxSet){
            numbers->max = number;
            maxSet = 1;
         }
         if(number < numbers->min || !minSet){
            numbers->min = number;
            minSet = 1;
         }
         numbers->size++;
      }
      free(line);
      return 0;
   }
}

void calculateMode(Numbers *numbers){
   int frequency[] = {0,0,0,0,0,0,0,0,0,0};
   for(int i = 0; i < numbers->size; i++){
      for(int j = 0; j < numbers->size; j++){
         if(i != j){
            if(numbers->numbers[i] == numbers->numbers[j]){
               frequency[i] += 1;
            }
         }
      }
   }
   int index = 0;
   for(int i = 0; i < numbers->size; i++){
      for(int j = 0; j < numbers->size; j++){
         if(frequency[index] < frequency[j]){
            index = i;
         }
      }
   }
   numbers->mode = numbers->numbers[index];
}

void calculateMean(Numbers *numbers){
  double sum = 0;
  for(int i = 0; i < numbers->size; i++){
      sum += numbers->numbers[i];
  }
  numbers->mean = (sum/numbers->size);
}

void calcMedian(Numbers *numbers){
   double temp;
   for(int i = 0; i < numbers->size-1; i++){
      for(int j = i+1; j < numbers->size; j++){
         if(numbers->numbers[i] < numbers->numbers[j]){
            temp = numbers->numbers[i];
            numbers->numbers[i] = numbers->numbers[j];
            numbers->numbers[j] = temp;
         }
      }
   }
   if(numbers->size % 2 == 0){
      numbers->median = ((numbers->numbers[numbers->size/2] + numbers->numbers[numbers->size/2-1]) / 2.0);
   }else{
      numbers->median = numbers->numbers[numbers->size/2];
   }
}


//Old version of median calculation
//void calculateMedian(Numbers *numbers){
//        
//   if(numbers->max == numbers->min){
//         numbers->median = numbers->max;
//   }else{
//      numbers->median = ((numbers->max - numbers->min)/2)+numbers->min;   
//   }
//}

int getSize(Numbers *numbers){
   return numbers->size;
}

void printNumbers(Numbers *numbers){
   for(int i = 0; i < numbers->size; i++){
      printf("%f\n", numbers->numbers[i]);
   }
}
