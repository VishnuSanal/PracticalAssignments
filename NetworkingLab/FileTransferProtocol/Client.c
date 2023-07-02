#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PORT 5035
#define MAX 60

int main() {

  int socketFD;

  struct sockaddr_in serverAddress;

  char fileName[MAX], line[MAX];

  socketFD = socket(AF_INET, SOCK_STREAM, 0);

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(PORT);

  if (connect(socketFD, (struct sockaddr *)&serverAddress,
              sizeof(serverAddress)) != 0) {
    printf("Connection with the server failed...\n");
    return 1;
  } else
    printf("Connected to the server..\n");

  printf("\nEnter the source file name: ");
  scanf("%s", fileName);

  if (access(fileName, F_OK) != 0) {
    printf("Something went wrong!\n");
    return 1;
  }

  write(socketFD, fileName, MAX);

  printf("File sent.\n");

  close(socketFD);

  return 0;
}
