#include <stdio.h>
#include <stdbool.h>

int main() {

  int wsize, pCount, sentFrame = 0, rtrans;
  char ack;

  printf("Enter window size :");
  scanf("%d", &wsize);
  printf("Enter packet count :");
  scanf("%d", &pCount);

  for (int i = 0; i < pCount; i++) {
    printf("\n");
    for (int j = 0; j < wsize; j++) {
      printf("Frame %d has been transmitted\n", sentFrame++);

      if (sentFrame == pCount)
        break;
    }

    while (true) {
      scanf("%c", &ack);
      printf("\nIs there any packet lost during transmission? : ");
      scanf("%c", &ack);

      if (ack == 'y' || ack == 'Y') {

        printf("\nEnter losted packetNo : ");
        scanf("%d", &rtrans);
        printf("Frame %d has been retransmitted\n", rtrans);
      }
      else{
        break;
      }
    }
    if(sentFrame >= pCount){
      break;
    }
  }
  
  printf("Transmission completed...");
  return 0;
}