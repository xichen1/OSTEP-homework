#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // fork, write
#include <fcntl.h>  // open
#include <sys/wait.h>

// How to let the parent process always print first, without using wait();
// Simply adding some i/o operation before calling printf("goodBye\n") in parent process.
// If the parent process runs first, when waiting the i/o to be done,
// the child process will print "hello".
int main(int argc, char *argv[])
{
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("hello\n");
  }
  else
  {
    int fd = open("./c3.txt", O_WRONLY | O_CREAT);
    write(fd, "c3", 2);
    printf("goodBye\n");
  }
  return 0;
}