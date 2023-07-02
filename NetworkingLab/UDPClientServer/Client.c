#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080

int main() {

  int socketFD;
  struct sockaddr_in serverAddress;

  socketFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

  if (socketFD == -1) {
    printf("\nSocket creation failed.");
    return 1;
  }

  printf("\nSocket successfully created!");

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(PORT);

  char buffer[MAX];

  while (true) {
    bzero(&buffer, MAX);

    printf("\nEnter the string: ");

    int n = 0;
    while ((buffer[n++] = getchar()) != '\n')
      ;

    sendto(socketFD, buffer, sizeof(buffer), 0,
           (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    bzero(&buffer, MAX);

    socklen_t len;

    recvfrom(socketFD, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&serverAddress, &len);

    printf("\tFrom Server: %s", buffer);
  }

  close(socketFD);

  return 0;
}