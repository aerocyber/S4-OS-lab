#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
  int pid = fork();

  if (pid < 0)
  {
    printf("Fork failed\n");
    exit(1);
  }
  else if (pid == 0)
  {
    sleep(5);
    printf("Child process, PID: %d\n", getpid());
    exit(0);
  }
  else
  {
    printf("Parent process, PID: %d\n", getpid());
    wait(NULL);
    exit(0);
  }

  return 0;
}
