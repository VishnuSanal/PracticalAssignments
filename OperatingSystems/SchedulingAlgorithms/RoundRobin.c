#include <stdbool.h>
#include <stdio.h>

void getWaitingTime(int burstTime[], int waitingTime[], int quantum, int n) {

  int remainingBurstTime[n];

  for (int i = 0; i < n; i++)
    remainingBurstTime[i] = burstTime[i];

  int currentTime = 0;

  while (true) {

    bool done = true;

    for (int i = 0; i < n; i++) {

      if (remainingBurstTime[i] <= 0)
        continue;

      done = false;

      int prevTime = currentTime;

      if (remainingBurstTime[i] > quantum) {
        currentTime += quantum;

        remainingBurstTime[i] -= quantum;
      } else {
        currentTime += remainingBurstTime[i];

        waitingTime[i] = currentTime - burstTime[i];

        remainingBurstTime[i] = 0;
      }

      printf("[ %d P%d %d ]", prevTime, i, currentTime);
    }

    if (done == true)
      break;
  }
}

void getTurnAroundTime(int burstTime[], int waitingTime[], int turnAroundTime[],
                       int n) {
  for (int i = 0; i < n; i++)
    turnAroundTime[i] = burstTime[i] + waitingTime[i];
}

int main() {

  int n, quantum, totalWaitingTime = 0, totalTurnAroundTime = 0;

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  int waitingTime[n], turnAroundTime[n], burstTime[n];

  for (int i = 0; i < n; i++) {

    printf("Enter the Burst Time of %dth process: ", i);
    scanf("%d", &burstTime[i]);
  }

  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  getWaitingTime(burstTime, waitingTime, quantum, n);

  getTurnAroundTime(burstTime, waitingTime, turnAroundTime, n);

  printf("\nPID\tBT\tWT\tTAT\n");

  for (int i = 0; i < n; i++) {

    totalWaitingTime += waitingTime[i];

    totalTurnAroundTime += turnAroundTime[i];

    printf("P%d	", i);
    printf("%d	", burstTime[i]);

    printf("%d	", waitingTime[i]);
    printf("%d	\n", turnAroundTime[i]);
  }

  printf("\nAverage WaitingTime: %f", (float)totalWaitingTime / (float)n);
  printf("\nAverage TurnAroundTime: %f", (float)totalTurnAroundTime / (float)n);

  printf("\n\n");

  return 0;
}
