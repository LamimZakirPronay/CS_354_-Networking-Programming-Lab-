#include<stdlib.h>  
 #include<stdio.h>  
 #include<string.h>  
 #include<unistd.h>  
 #include<sys/types.h>  
 #include<sys/ipc.h>  
 #include<sys/msg.h>  
#define MAX 10
// structure for message queue
struct msg_buffer {
   long meg_type;
   char meg_text[100];
} message;
int main() {
   key_t my_key;
   int msg_id;
   my_key = ftok("progfile", 65); 
   msg_id = msgget(my_key, 0666 | IPC_CREAT); 
   message.meg_type = 1;
   printf("Write Message : ");
   fgets(message.meg_text , 1000,stdin);
   msgsnd(msg_id, &message, sizeof(message), 0); 
   printf("Sent message is : %s \n", message.meg_text);
   return 0;
}