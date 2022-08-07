#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>

void main() {

	int shared_memory_id = shmget((key_t) 11122, 1024, 0666 | IPC_CREAT);

	printf("\nShared Memory Key: %d\n", shared_memory_id);

	void *shared_memory = shmat(shared_memory_id, NULL, 0);
	
	printf("\nProcess attached to shared memory at: %p\n", shared_memory);
	
	printf("\nEnter some data to write to shared memory: \n");
	
	char buffer[100];
	
	read(0, buffer, sizeof(buffer));
	
	strcpy(shared_memory, buffer);
	
	printf("\nData: %s\n\n", (char*) shared_memory);

}
