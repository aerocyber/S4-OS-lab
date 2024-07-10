#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main() 
{
  key_t k = ftok("shmfile", 65);
  int shmid = shmget(k, 1024, 0666|IPC_CREAT);
  char * str = shmat(shmid, (void *)0, 0);
  printf("Got data:\t%s\n", str);
  shmdt(str);
  shmctl(shmid, IPC_RMID, NULL);
}
