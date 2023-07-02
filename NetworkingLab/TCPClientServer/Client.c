#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

  int socketFD;
  struct sockaddr_in serverAddress, clientAddress;

  socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (socketFD == -1) {
    printf("\nSocket creation failed.");
    return 1;
  }

  printf("\nSocket successfully created!");

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(8080);

  if (connect(socketFD, (struct sockaddr *)&serverAddress,
              sizeof(serverAddress)) != 0) {
    printf("\nServer connection failed.");
    return 1;
  }

  printf("\nServer connected successfully!");

  char buffer[80];

  while (true) {

    printf("\nTo Server: ");

    int n;
    while ((buffer[n++] = getchar()) != '\n')
      ;

    write(socketFD, buffer, sizeof(buffer));

    read(socketFD, buffer, sizeof(buffer));

    printf("\n\tFrom Server : %s", buffer);
  }

  printf("\n\n");
  close(socketFD);

  return 0;
}