#include <stdbool.h>
#include <stdio.h>

int main() {

  int windowSize, sentFrame = 0, acknowledgedFrame, packetCount;

  char acknowledgement;

  printf("Enter the number of packets: ");
  scanf("%d", &packetCount);

  for (int i = 0; i < packetCount; i++) {

    printf("\n");

    printf("Frame %d has been transmitted\n", sentFrame++);

    scanf("%c", &acknowledgement);

    while (true) {

      printf("\n");

      printf("Is frame %d acknowledged? (Y / N): ", i);
      scanf("%c", &acknowledgement);

      if (acknowledgement == 'Y')
        break;
      else {
        printf("\nFrame %d retransmitted\n", i);

        scanf("%c", &acknowledgement);
      }
    }
  }

  return 0;
}
