#include <stdbool.h>
#include <stdio.h>

int main() {

  int sentFrame = 0, packetCount;

  char acknowledgement;

  printf("Enter the number of packets: ");
  scanf("%d", &packetCount);

  for (int i = 0; i < packetCount; i++) {

    printf("\n");

    printf("Frame %d has been transmitted\n", sentFrame++);

    while (true) {

      scanf("%c", &acknowledgement); // to prevernt skipping of input

      printf("\nIs frame %d acknowledged? (Y / N): ", i);
      scanf("%c", &acknowledgement);

      if (acknowledgement == 'Y')
        break;
      else
        printf("\nFrame %d retransmitted\n", i);
    }
  }

  return 0;
}
