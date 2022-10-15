#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  pid_t PID = fork();

  if (PID == -1)
    printf("\nError in creating process\n");
  else if (PID == 0) {
    printf("\nHelloChildProcess!\n");
    printf("\nPID: %d\n", getpid());
    printf("\nParent PID: %d\n", getppid());
  } else {
    printf("\nHelloParentProcess!\n");
    printf("\nPID: %d\n", getpid());
    printf("\nParent PID: %d\n", getppid());
  }

  return 0;
}