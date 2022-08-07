#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main() {

	pid_t PID = fork();
	
	if(PID == -1)
		printf("\nError in creating process\n");
	else if(PID == 0) {
		printf("\nHelloChildProcess!\n");
		printf("\nPID: %d\n", getpid());
		printf("\nParent PID: %d\n", getppid());
	} else {
		printf("\nHelloParentProcess!\n");
		printf("\nPID: %d\n", getpid());
		printf("\nParent PID: %d\n", getppid());
	}

}
