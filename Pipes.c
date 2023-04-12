#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefds[2];
	
   int success;
   int pid;
   char writemessages[3][20]={"Hi", "Hello","bye"};
   char readmessage[20];
   success = pipe(pipefds);
   if (success== -1) {
      printf("Pipe not cretaed \n");
      return 1;
   }
   pid = fork();
   
   // Child process
   if (pid == 0) {
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Child Process - Reading from pipe – Message 1 is %s\n", readmessage);
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Child Process - Reading from pipe – Message 2 is %s\n", readmessage);
      read(pipefds[0], readmessage, sizeof(readmessage));
      printf("Child Process - Reading from pipe – Message 3 is %s\n", readmessage);
   } else { //Parent process
      printf("Parent Process - Writing to pipe - Message 1 is %s\n", writemessages[0]);
      write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
      printf("Parent Process - Writing to pipe - Message 2 is %s\n", writemessages[1]);
      write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
      printf("Parent Process - Writing to pipe - Message 3 is %s\n", writemessages[2]);
      write(pipefds[1], writemessages[1], sizeof(writemessages[2]));
   }
   return 0;
}