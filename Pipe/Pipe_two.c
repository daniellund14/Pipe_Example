#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <Numbers.h>

int main(int argc, char *argv[]){
   int readBuffer;
   int pid = atoi(argv[2]);
   read(pid, &readBuffer, sizeof(readBuffer));
   //int sid = atoi(readBuffer);
   printf("Piped ID: %d\n", readBuffer);
   double *data = shmat(readBuffer, NULL, 0);
   Numbers *numbers = malloc(sizeof(Numbers));
   numbers->fileName = argv[1];
   readFile(numbers);
   calculateMean(numbers);
   double mean = numbers->mean;
   data[0] = mean;
  // int shid = shmget(sid, sizeof(double), IPC_CREAT | 0666);
   //data = (char *) shmat(sid, 0, 0);
   //data = "test1"; 
   //shmdt(data);
   //shmctl(sid, IPC_RMID, NULL); 
   return 0;
}
