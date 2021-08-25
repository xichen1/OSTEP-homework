#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // fork, write
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> // open

// I guess I have to revisit some C knowledge lol.
// What happens when opening a file, create a process and then
// make child and parent write to the file concurrently?
// One of the writing will be done first and then the other one.

int main(int argc, char *argv[])
{
  char *words[3];
  words[0] = "a";
  words[1] = "b";
  words[2] = "c";

  char *numbers[3];
  numbers[0] = "1";
  numbers[1] = "2";
  numbers[2] = "3";
  int file = open("./c2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
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
    write(file, "abcdef", 6);
    printf("hello, I am child (pid:%d)\nI wrote word ab.\n", (int)getpid());
  }
  else
  {
    write(file, "123456", 6);
    // parent goes down this path (original process)
    printf("hello, I am parent of %d (pid:%d)\n I wrote number 12\n",
           rc, (int)getpid());
  }
}