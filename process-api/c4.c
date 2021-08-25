#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // fork, execvp
#include <string.h>

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
    char *myargs[2];
    myargs[0] = strdup("/bin/ls");
    myargs[1] = NULL;
    execvp(myargs[0], myargs);
    // runExec("execl");
    // runExec("execlp");
    // runExec("execle");
    // runExec("execv");
    printf("failed\n");
  }
  else
  {
    printf("This is the parent process\n");
  }
}

// void runExec(char type[])
// {
//   char *myargs[2];
//   myargs[0] = strdup("/bin/ls");
//   myargs[1] = NULL;
//   if (type == "execl")
//   {
//     execl(myargs[0], myargs);
//   }
//   else if (type == "execlp")
//   {
//     execlp(myargs[0], myargs);
//   }
//   else if (type == "execle")
//   {
//     execle(myargs[0], myargs);
//   }
//   else if (type == "execv")
//   {
//     execv(myargs[0], myargs);
//   }
// }
