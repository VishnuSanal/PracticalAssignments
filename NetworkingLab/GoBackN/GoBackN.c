#include <stdbool.h>
#include <stdio.h>

int main() {
  int windowSize, sentFrame = 0, acknowledgedFrame, packetCount;

  printf("Enter the window size: ");
  scanf("%d", &windowSize);

  printf("Enter the number of packets: ");
  scanf("%d", &packetCount);

  for (int i = 0; i < packetCount; i++) {

    printf("\n");

    for (int i = 0; i < windowSize; i++) {

      printf("Frame %d has been transmitted\n", sentFrame++);

      if (sentFrame == packetCount)
        break;
    }

    while (true) {

      printf("\nPlease enter the last acknowledgement: ");
      scanf("%d", &acknowledgedFrame);

      if (acknowledgedFrame <= sentFrame) {
        sentFrame = acknowledgedFrame;
        break;
      } else {
        printf("Invalid acknowledgement");
      }
    }

    if (acknowledgedFrame == packetCount) {
      printf("Transmission completed.\n");
      break;
    }
  }

  return 0;
}
