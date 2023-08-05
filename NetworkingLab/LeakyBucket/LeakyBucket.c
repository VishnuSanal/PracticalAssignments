#include <stdio.h>

int main() {
  int packetSize, outputRate, bucketSize, numberOfPackets, remainingSize = 0;

  printf("\nEnter the Output Rate: ");
  scanf("%d", &outputRate);

  printf("Enter the Bucket Size: ");
  scanf("%d", &bucketSize);

  printf("Enter the Number of Packets: ");
  scanf("%d", &numberOfPackets);

  for (int i = 0; i < numberOfPackets; i++) {

    printf("Enter the incoming packet size: ");
    scanf("%d", &packetSize);

    if (packetSize <= bucketSize - remainingSize) {
      remainingSize += packetSize;

      printf("Bucket contents: (%d/%d)\n", remainingSize, bucketSize);
    } else {

      printf("Dropped %d packets\n",
             packetSize - bucketSize + remainingSize);
      printf("Bucket contents: (%d/%d)\n", remainingSize, bucketSize);
      remainingSize = bucketSize;
    }

    remainingSize = remainingSize - outputRate;

    printf("After outgoing, Bucket contents: (%d/%d)\n",
           remainingSize, bucketSize);
  }
}