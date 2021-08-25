#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // open
#include <sys/wait.h>

int main(int argv, char *argc[])
{
  char word[6];
  int p[2];
  if (pipe(p) < 0)
  {
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }

  int child = fork();
  if (child < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (child == 0)
  {
    int grand = fork();
    if (grand < 0)
    {
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if (grand == 0)
    {
      close(p[1]);
      read(p[0], word, 6);
      write(STDOUT_FILENO, word, 6);
    }
    else
    {
      close(p[0]);
      write(p[1], "hello\n", 6);
      wait(NULL);
    }
  }
  else
  {
    wait(NULL);
  }
  return 0;
}