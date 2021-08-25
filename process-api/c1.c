#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Before calling fork(), create a new variable x and assign some value,
// what will happen to the variable if both child and parent change it?

// OUTPUT:
// hello world (pid:308)
// hello, I am parent of 309 (pid:308)
//  I changed x to 100
// hello, I am child (pid:309)
//  I changed x to 0
// 100
// 0

// This means each parent and child process has its own private variable x,
// and changed them independently.

// Interesting fact is no matter how many times I tried, the order never changed.
// The order is always: parent changes value, child changes value, print parent value, print child value
// It might caused because some policy's rule.

int main(int argc, char *argv[])
{
  printf("hello world (pid:%d)\n", (int)getpid());
  int x = 200;
  int rc = fork();
  if (rc < 0)
  {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // child (new process)
    x = 0;
    printf("hello, I am child (pid:%d)\n I changed x to 0\n", (int)getpid());
  }
  else
  {
    x = 100;
    // parent goes down this path (original process)
    printf("hello, I am parent of %d (pid:%d)\n I changed x to 100\n",
           rc, (int)getpid());
  }
  printf("%d\n", x);
  return 0;
}