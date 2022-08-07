#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int PID[], int burstTime[], int priority[], int n) {

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)

      if (priority[j] > priority[j + 1]) {

        swap(&PID[i], &PID[j + 1]);
        swap(&priority[i], &priority[j + 1]);
        swap(&burstTime[i], &burstTime[j + 1]);
      }
}

void getWaitingTime(int burstTime[], int waitingTime[], int n) {

  waitingTime[0] = 0;

  int prevTime = 0, currentTime = 0;

  for (int i = 0; i < n; i++) {

    waitingTime[i] = 0;

    if (i == 0)
      prevTime = 0;
    else
      prevTime = currentTime;

    for (int j = 0; j < i; j++)
      waitingTime[i] += burstTime[j];

    currentTime += burstTime[i];

    printf("[ %d P%d %d ]", prevTime, i, currentTime);
  }
}

void getTurnAroundTime(int burstTime[], int waitingTime[], int turnAroundTime[],
                       int n) {
  for (int i = 0; i < n; i++)
    turnAroundTime[i] = burstTime[i] + waitingTime[i];
}

int main() {

  int n, totalWaitingTime = 0, totalTurnAroundTime = 0;

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  int waitingTime[n], turnAroundTime[n], burstTime[n], priority[n], PID[n];

  for (int i = 0; i < n; i++) {

    PID[i] = i;

    printf("\nEnter the Burst Time of %dth process: ", i);
    scanf("%d", &burstTime[i]);

    printf("Enter the Priority of %dth process: ", i);
    scanf("%d", &priority[i]);
  }

  printf("\n");

  bubbleSort(PID, burstTime, priority, n);

  getWaitingTime(burstTime, waitingTime, n);

  getTurnAroundTime(burstTime, waitingTime, turnAroundTime, n);

  printf("\n\nPID\tBT\tWT\tTAT\n");

  for (int i = 0; i < n; i++) {

    totalWaitingTime += waitingTime[i];

    totalTurnAroundTime += turnAroundTime[i];

    printf("P%d	", PID[i]);
    printf("%d	", burstTime[i]);

    printf("%d	", waitingTime[i]);
    printf("%d	\n", turnAroundTime[i]);
  }

  printf("\nAverage WaitingTime: %f", (float)totalWaitingTime / (float)n);
  printf("\nAverage TurnAroundTime: %f", (float)totalTurnAroundTime / (float)n);

  printf("\n\n");

  return 0;
}
