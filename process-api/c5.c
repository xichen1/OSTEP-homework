#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// the wait() call in parent process returns the pid of child process
int main(int argv, char *argc[])
{
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("this is the child process, the pid is %d\n", getpid());
  }
  else
  {
    int res = wait(NULL);
    printf("this is the parent process, the result of wait is %d, the pid is %d\n", res, getpid());
  }
  return 0;
}