#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 5035
#define MAX 60

int main() {

  int socketFD, connectionFD;
  socklen_t clientLength;

  struct sockaddr_in serverAddress, clientAddress;

  socketFD = socket(AF_INET, SOCK_STREAM, 0);

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(PORT);

  if ((bind(socketFD, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress))) != 0) {
    printf("Socket binding failed...\n");
    exit(0);
  } else
    printf("Socket successfully binded..\n");

  printf("\nListening...");

  listen(socketFD, 5);

  clientLength = sizeof(clientAddress);

  connectionFD =
      accept(socketFD, (struct sockaddr *)&clientAddress, &clientLength);

  close(socketFD);

  char fileName[MAX], buffer[4096];

  read(connectionFD, &fileName, MAX);

  printf("\nFilename from Client: %s\n", fileName);

  if (access(fileName, F_OK) != 0) {
    printf("Something went wrong!\n");
    exit(0);
  }

  FILE *file = fopen(fileName, "r");

  printf("\nFile contents:\n");
  while (fgets(buffer, 4096, file) != NULL) {
    printf("%s", buffer);
  }

  fclose(file);

  return 0;
}
