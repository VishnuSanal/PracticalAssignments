#include <stdio.h>

int main() {

  int numberOfBlocks, numberOfProcesses;

  printf("Blocks: ");
  scanf("%d", &numberOfBlocks);

  int blockSize[numberOfBlocks];

  printf("\nBlock Sizes:\n\n");
  for (int i = 0; i < numberOfBlocks; i++) {

    printf("%dth Block: ", i);
    scanf("%d", &blockSize[i]);
  }

  printf("\nProcesses: ");
  scanf("%d", &numberOfProcesses);

  int processSize[numberOfProcesses], allocate[numberOfProcesses];

  for (int i = 0; i < numberOfProcesses; i++)
    allocate[i] = -1;

  printf("\nProcess Sizes:\n\n");
  for (int i = 0; i < numberOfProcesses; i++) {

    printf("%dth Process: ", i);
    scanf("%d", &processSize[i]);
  }

  for (int i = 0; i < numberOfProcesses; i++)
    for (int j = 0; j < numberOfBlocks; j++)
      if (blockSize[j] >= processSize[i]) {
        allocate[i] = j;

        blockSize[j] -= processSize[i];

        break;
      }

  printf("\nProcess\tProcessSize\tBlock\n");

  for (int i = 0; i < numberOfProcesses; i++) {

    printf("%d\t%d\t\t", i, processSize[i]);

    if (allocate[i] != -1)
      printf("%d\n", allocate[i]);
    else
      printf("NotAllocated\n");
  }

  printf("\n\n");

  return 0;
}