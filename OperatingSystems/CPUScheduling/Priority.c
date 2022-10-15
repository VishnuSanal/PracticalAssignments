#include <stdio.h>

struct Process {
  int PID;
  int burstTime;
  int priority;

  int turnAroundTime;
  int waitingTime;
};

void swap(struct Process *one, struct Process *two) {

  struct Process temp = *one;
  *one = *two;
  *two = temp;
}

void bubbleSort(struct Process process[], int n) {

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (process[j].priority > process[j + 1].priority)
        swap(&process[j], &process[j + 1]);
}

int main() {

  int n, totalWaitingTime = 0, totalTurnAroundTime = 0;

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  struct Process process[n];

  for (int i = 0; i < n; i++) {

    process[i].PID = i;

    printf("\nEnter the Burst Time of %dth process: ", i);
    scanf("%d", &process[i].burstTime);

    printf("Enter the Priority of %dth process: ", i);
    scanf("%d", &process[i].priority);
  }

  bubbleSort(process, n);

  process[0].waitingTime = 0;

  int currentTime = 0, prevTime = 0;

  for (int i = 0; i < n; i++) {

    process[i].waitingTime = 0;

    if (i == 0)
      prevTime = 0;
    else
      prevTime = currentTime;

    for (int j = 0; j < i; j++)
      process[i].waitingTime += process[j].burstTime;

    currentTime = process[i].waitingTime + process[i].burstTime;

    printf("[ %d P%d %d ]", prevTime, process[i].PID, currentTime);
  }

  process[0].turnAroundTime = process[0].burstTime;

  for (int i = 1; i < n; i++) {
    process[i].turnAroundTime = process[i].burstTime + process[i].waitingTime;
  }

  printf("\n\nPID\tP\tBT\tWT\tTAT\n");

  for (int i = 0; i < n; i++) {

    totalWaitingTime += process[i].waitingTime;
    totalTurnAroundTime += process[i].turnAroundTime;

    printf("P%d	", process[i].PID);
    printf("%d	", process[i].priority);
    printf("%d	", process[i].burstTime);

    printf("%d	", process[i].waitingTime);
    printf("%d	\n", process[i].turnAroundTime);
  }

  printf("\nAverage WaitingTime: %f", (float)totalWaitingTime / (float)n);
  printf("\nAverage TurnAroundTime: %f", (float)totalTurnAroundTime / (float)n);

  printf("\n\n");

  return 0;
}
