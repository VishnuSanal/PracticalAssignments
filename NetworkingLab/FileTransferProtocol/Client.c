#include <arpa/inet.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#define MAX 80

int main() {

  int socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (socketFD == -1) {
    printf("\nSocket creation failed.");
    return 1;
  }

  printf("\nSocket creation successful!");

  struct sockaddr_in serverAddress, clientAddress;

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(5035);

  if (connect(socketFD, (struct sockaddr *)&serverAddress,
              sizeof(serverAddress)) != 0) {
    printf("\nSocket connect failed.");
    return 1;
  }

  printf("\nSocket connection successful!");

  printf("\nFileName: ");

  char buffer[MAX] = "file.txt";
  scanf("%s", buffer);

  send(socketFD, buffer, sizeof(buffer), 0);

  close(socketFD);

  printf("\n\n");
  return 0;
}
