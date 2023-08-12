#include <stdbool.h>
#include <stdio.h>

int main() {

  int windowSize, packetCount, sentFrame = 0, failedFrame;
  char acknowledgment;

  printf("Enter window size: ");
  scanf("%d", &windowSize);

  printf("Enter packet count: ");
  scanf("%d", &packetCount);

  for (int i = 0; i < packetCount; i++) {

    for (int j = 0; j < windowSize; j++) {
      printf("\nFrame %d has been transmitted", sentFrame++);

      if (sentFrame == packetCount)
        break;
    }

    scanf("%c", &acknowledgment);
    printf("\n\nAny packets lost during transmission? (Y/N): ");
    scanf("%c", &acknowledgment);

    while (acknowledgment != 'N') {

      printf("\nEnter serial number of lost packet: ");
      scanf("%d", &failedFrame);

      if (failedFrame >= sentFrame) {
        printf("Invalid serial number");
        continue;
      }

      printf("Frame %d has been retransmitted", failedFrame);

      scanf("%c", &acknowledgment);
      printf("\n\nAnymore packets lost during transmission? (Y/N): ");
      scanf("%c", &acknowledgment);
    }

    if (sentFrame >= packetCount)
      break;
  }

  printf("\nTransmission complete.\n\n");
  return 0;
}