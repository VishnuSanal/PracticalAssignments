#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080

int main() {

  int socketFD;
  struct sockaddr_in serverAddress, clientAddress;

  socketFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  if (socketFD == -1) {
    printf("\nSocket creation failed.");
    return 1;
  }

  printf("\nSocket successfully created!");

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);

  if ((bind(socketFD, (struct sockaddr *)&serverAddress,
            sizeof(serverAddress))) != 0) {
    printf("\nSocket binding failed.");
    return 1;
  }

  printf("\nSocket successfully bound!");

  socklen_t len = sizeof(clientAddress);

  char buffer[MAX];

  while (true) {

    bzero(&buffer, MAX);

    recvfrom(socketFD, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&clientAddress, &len);

    printf("From client: %s\t To client : ", buffer);

    bzero(&buffer, MAX);

    int n = 0;
    while ((buffer[n++] = getchar()) != '\n')
      ;

    sendto(socketFD, buffer, sizeof(buffer), 0,
           (struct sockaddr *)&clientAddress, sizeof(clientAddress));
  }

  close(socketFD);

  return 0;
}
