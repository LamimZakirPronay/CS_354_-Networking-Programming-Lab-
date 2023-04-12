#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
   long meg_type;
   char meg_text[100];
} message;
int main() {
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65);

   msg_id = msgget(my_key, 0666 | IPC_CREAT); 

   msgrcv(msg_id, &message, sizeof(message), 1, 0); 
   
   printf("Received Message is : %s \n", message.meg_text);

   msgctl(msg_id, IPC_RMID, NULL); 
   return 0;
  
}