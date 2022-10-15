#include <stdio.h>
#include <stdlib.h>

int main() {

  int n, totalHeadMovement = 0, previous = 0, current = 0;

  printf("Number of Requests: ");
  scanf("%d", &n);

  int requests[n];

  printf("Initial Head Position: ");
  scanf("%d", &previous);

  printf("Requests Sequence:\n");
  for (int i = 0; i < n; i++) {

    printf("%dth Request: ", i);
    scanf("%d", &requests[i]);
  }

  printf("Traversal Order: ");
  for (int i = 0; i < n; i++) {

    printf("%d => ", requests[i]);

    totalHeadMovement += abs(requests[i] - previous);
    previous = requests[i];
  }

  printf("\n\nTotal Head Movement: %d", totalHeadMovement);

  printf("\n\n");

  return 0;
}