#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int fd[2];
	pid_t pid;
	pipe(fd);
   char buf[20];
   char stfd[20];
   char * data;
	pid = fork();
	//Child process
	if(pid == 0){
      //Child should read
		close(fd[1]);
      sprintf(stfd, "%d", fd[0]);
		execlp("./Pipe_two", "Pipe_two", "Nums.txt", stfd, NULL);
		
	}else{
		/* Parent Process */

	   int sid = shmget(IPC_PRIVATE, sizeof(double), IPC_CREAT | 0666);
      char stid[20];
      sprintf(stid, "%d", sid);
      write(fd[1], &sid, sizeof(sid));
		wait(NULL);
      double *data = (double *) shmat(sid, NULL, 0);
      printf("%f\n" , data[0]);
		//read(fd[0], buf, 15);
      //data = (char *) shmat(sid, NULL, 0);
      //printf("%s\n", data);
      //shmdt(data);
		//printf("buf: %s\n", buf);
      shmctl(sid, IPC_RMID, NULL);
		
	}	
}
