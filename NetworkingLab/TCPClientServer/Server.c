#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080

int main() {

  int socketFD, connectionFD;
  struct sockaddr_in serverAddress, clientAddress;

  socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (socketFD == -1) {
    printf("socket creation failed...\n");
    exit(0);
  } else
    printf("Socket successfully created..\n");

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);

  if ((bind(socketFD, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress))) != 0) {
    printf("Socket binding failed...\n");
    exit(0);
  } else
    printf("Socket successfully binded..\n");

  if ((listen(socketFD, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  } else
    printf("Server listening..\n");

  socklen_t len = sizeof(clientAddress);

  connectionFD = accept(socketFD, (struct sockaddr *)&clientAddress, &len);

  if (connectionFD < 0) {
    printf("Server accept failed...\n");
    exit(0);
  } else
    printf("Server accept the client...\n");

  char buffer[MAX];

  while (true) {
    bzero(buffer, MAX);

    read(connectionFD, buffer, sizeof(buffer));

    printf("From client: %s\t To client : ", buffer);
    bzero(buffer, MAX);

    int n = 0;
    while ((buffer[n++] = getchar()) != '\n')
      ;

    write(connectionFD, buffer, sizeof(buffer));

    if (strncmp("exit", buffer, 4) == 0) {
      printf("Server Exit...\n");
      break;
    }
  }

  close(socketFD);
}
