#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// waitpid() can specify wait for which process
// waitpid has more option to choose
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

    printf("this is the child process, pid is %d\n", getpid());
  }
  else
  {
    int res = waitpid(rc, NULL, WUNTRACED);
    printf("this is the parent process, the result of waitpid is %d\n", res);
  }
  return 0;
}