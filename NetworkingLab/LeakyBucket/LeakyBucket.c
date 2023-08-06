#include <stdio.h>

int main() {
  int packetSize, outputRate, bucketSize, numberOfPackets, bucketContents = 0;

  printf("\nEnter the Output Rate: ");
  scanf("%d", &outputRate);

  printf("Enter the Bucket Size: ");
  scanf("%d", &bucketSize);

  printf("Enter the Number of Packets: ");
  scanf("%d", &numberOfPackets);

  for (int i = 0; i < numberOfPackets; i++) {

    printf("\nEnter the incoming packet size: ");
    scanf("%d", &packetSize);

    if (packetSize <= bucketSize - bucketContents)
      bucketContents += packetSize;
    else {

      printf("Dropped %d packets\n",
             packetSize - (bucketSize - bucketContents));
      bucketContents = bucketSize;
    }

    printf("Bucket contents: (%d/%d)\n", bucketContents, bucketSize);

    bucketContents -= outputRate;

    printf("After outgoing, Bucket contents: (%d/%d)\n", bucketContents,
           bucketSize);
  }
}
