#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

int main() {

  int n, totalHeadMovement = 0, previous = 0, diskSize, moveDir;

  printf("Number of Requests: ");
  scanf("%d", &n);

  printf("Initial Head Position: ");
  scanf("%d", &previous);

  printf("Total Disk Size: ");
  scanf("%d", &diskSize);

  int requests[n];

  printf("Requests Sequence:\n");
  for (int i = 0; i < n; i++) {

    printf("%dth Request: ", i);
    scanf("%d", &requests[i]);
  }

  printf("\nMove Direction -> Enter 0 for low and 1 for high: ");
  scanf("%d", &moveDir);

  bubbleSort(requests, n);

  int startIndex;
  for (int i = 0; i < n; i++)
    if (previous < requests[i]) {
      startIndex = i;
      break;
    }

  printf("\nTraversal Order: ");
  if (moveDir == 1) {

    for (int i = startIndex; i < n; i++) {

      printf("%d => ", requests[i]);

      totalHeadMovement += abs(requests[i] - previous);
      previous = requests[i];
    }

    totalHeadMovement += abs(diskSize - 1 - requests[n - 1]);
    previous = diskSize - 1;
    printf("%d => ", diskSize - 1);

    totalHeadMovement += abs(diskSize - 1);
    previous = 0;
    printf("%d => ", 0);

    for (int i = 0; i < startIndex; i++) {

      printf("%d => ", requests[i]);

      totalHeadMovement = totalHeadMovement + abs(requests[i] - previous);
      previous = requests[i];
    }

  } else {

    for (int i = startIndex - 1; i >= 0; i--) {

      printf("%d => ", requests[i]);

      totalHeadMovement += abs(requests[i] - previous);
      previous = requests[i];
    }

    totalHeadMovement += abs(requests[0]);
    previous = 0;
    printf("%d => ", 0);

    totalHeadMovement += abs(diskSize - 1);
    previous = diskSize - 1;
    printf("%d => ", diskSize - 1);

    for (int i = n - 1; i >= startIndex; i--) {

      printf("%d => ", requests[i]);

      totalHeadMovement = totalHeadMovement + abs(requests[i] - previous);
      previous = requests[i];
    }
  }

  printf("\n\nTotal Head Movement: %d", totalHeadMovement);

  printf("\n\n");

  return 0;
}
