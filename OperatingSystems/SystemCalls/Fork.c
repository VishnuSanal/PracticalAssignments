#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  pid_t PID = fork();

  if (PID == -1)
    printf("\nError in creating process\n");
  else if (PID == 0)
    printf("\nHelloChildProcess!\n");
  else
    printf("\nHelloParentProcess!\n");

  return 0;
}