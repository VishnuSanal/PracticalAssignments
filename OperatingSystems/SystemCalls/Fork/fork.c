#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main() {

	pid_t PID = fork();
	
	if(PID == -1)
		printf("\nError in creating process\n");
	else if(PID == 0)
		printf("\nHelloChildProcess!\n");
	else
		printf("\nHelloParentProcess!\n");

}
