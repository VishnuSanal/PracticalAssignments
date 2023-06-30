#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Frame {
  char acknowledgement;
};

int main() {

  int n, r;

  printf("\nEnter the number of frames: ");
  scanf("%d", &n);

  struct Frame frames[n];

  for (int i = 0; i < n; i++) {

    sleep(rand() % 2);

    printf("\nPackets %d sent successfully", i);

    frames[i].acknowledgement = 'y';
  }

  printf("\n\nEnter the frame whose acknowledgement was not received: ");
  scanf("%d", &r);

  frames[r].acknowledgement = 'n';

  printf("\nResending packet %d", r);

  sleep(rand() % 3);

  frames[r].acknowledgement = 'y';

  printf("\n\nPacket %d received successfully\n", r);
}
