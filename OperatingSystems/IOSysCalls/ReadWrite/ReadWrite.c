#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

  int file_descriptor = open("test.txt", O_RDWR | O_CREAT);

  printf("\nFile Descriptor: %d\n", file_descriptor);

  if (file_descriptor == -1) {

    printf("\nError: Couldn't open file\n");
    return 1;
  }

  printf("\nThe file opened with read & write access\n");

  char buffer[100];

  printf("\nEnter a string value to write: ");

  scanf("%s", buffer);

  char message[strlen(buffer)];

  strcpy(message, buffer);

  write(file_descriptor, message, sizeof(message));

  lseek(file_descriptor, 0, SEEK_SET);

  read(file_descriptor, buffer, sizeof(message));

  printf("\n\"%s\" was written onto the file\n", buffer);

  close(file_descriptor);

  return 0;
}