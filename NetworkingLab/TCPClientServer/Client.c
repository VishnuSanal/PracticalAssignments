#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080

int main() {

  int socketFD, connectionFD;
  struct sockaddr_in serverAddress;

  socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (socketFD == -1) {
    printf("Socket creation failed...\n");
    exit(0);
  } else
    printf("Socket successfully created..\n");

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("192.168.1.4");
  serverAddress.sin_port = htons(PORT);

  if (connect(socketFD, (struct sockaddr *)&serverAddress,
              sizeof(serverAddress)) != 0) {
    printf("Connection with the server failed...\n");
    exit(0);
  } else
    printf("Connected to the server..\n");

  char buffer[MAX];
  int n;

  while (true) {
    bzero(buffer, sizeof(buffer));

    printf("Enter the string : ");
    n = 0;

    while ((buffer[n++] = getchar()) != '\n')
      ;

    write(socketFD, buffer, sizeof(buffer));

    bzero(buffer, sizeof(buffer));

    read(socketFD, buffer, sizeof(buffer));

    printf("\tFrom Server : %s", buffer);

    if ((strncmp(buffer, "exit", 4)) == 0) {
      printf("Client Exit...\n");
      break;
    }
  }

  close(socketFD);
}