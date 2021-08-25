#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// only parent prints one line, the child cannot print anything
int main(int argv, char *argc[])
{
  int rc = fork();
  int pid = getpid();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    close(STDOUT_FILENO);
    printf("this is the child process, pid is %d\n", getpid());
  }
  else
  {
    printf("this is the parent process, pid is %d\n", getpid());
  }
  return 0;
}