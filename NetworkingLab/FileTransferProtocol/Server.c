#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#define MAX 80

int main() {

  int socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP), connectionFD;

  if (socketFD == -1) {
    printf("\nSocket creation failed.");
    return 1;
  }

  printf("\nSocket creation successful!");

  struct sockaddr_in serverAddress, clientAddress;

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(5035);

  if (bind(socketFD, (struct sockaddr *)&serverAddress,
           sizeof(serverAddress)) != 0) {
    printf("\nSocket binding failed.");
    return 1;
  }

  printf("\nSocket binding successful!");

  if (listen(socketFD, 5) != 0) {
    printf("\nSocket listen failed.");
    return 1;
  }

  printf("\nSocket listening...");

  socklen_t len = sizeof(clientAddress);

  connectionFD = accept(socketFD, (struct sockaddr *)&clientAddress, &len);

  close(socketFD);

  if (connectionFD == -1) {
    printf("\nClient accept failed.");
    return 1;
  }

  printf("\nClient accept successful!");

  char buffer[MAX];

  bzero(buffer, MAX);

  recv(connectionFD, buffer, sizeof(buffer), 0);

  printf("\nFileName: %s\n", buffer);

  FILE *file = fopen(buffer, "r");
  
  if (file) {
    int c;
    while ((c = fgetc(file)) != EOF)
      putchar(c);
    fclose(file);
  } else
    printf("Something went wrong!\n");

  close(connectionFD);

  printf("\n\n");
  return 0;
}
