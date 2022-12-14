#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  pid_t PID = fork();

  if (PID == -1)
    printf("\nError in creating process\n");
  else if (PID == 0) {
    printf("\nHelloChildProcess!\n");
    exit(0);
  } else {
    printf("\nHelloParentProcess!\n");
    printf("\nParent waiting...\n");
    wait(NULL);
    printf("\nChild has been terminated\n");
  }

  printf("\nEnd\n");

  return 0;
}