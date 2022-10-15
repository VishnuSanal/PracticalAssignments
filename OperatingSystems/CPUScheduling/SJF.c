#include <stdio.h>

struct Process {

  int PID;
  int burstTime;

  int waitingTime;
  int turnAroundTime;
};

void swap(struct Process *a, struct Process *b) {
  struct Process temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(struct Process processes[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1; j++)
      if (processes[j].burstTime > processes[j + 1].burstTime)
        swap(&processes[j], &processes[j + 1]);
}

void getWaitingTime(struct Process processes[], int n) {

  int currentTime = 0, prevTime = 0;

  for (int i = 0; i < n; i++) {

    prevTime = currentTime;

    processes[i].waitingTime = 0;

    for (int j = 0; j < i; j++)
      processes[i].waitingTime += processes[j].burstTime;

    currentTime = processes[i].waitingTime + processes[i].burstTime;

    printf("[%d P%d %d]\t", prevTime, processes[i].PID, currentTime);
  }
}

void getTurnAroundTime(struct Process processes[], int n) {

  for (int i = 0; i < n; i++)
    processes[i].turnAroundTime =
        processes[i].burstTime + processes[i].waitingTime;
}

int main() {

  int n = 0, totalWaitingTime = 0, totalTurnAroundTime = 0;

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  struct Process processes[n];

  for (int i = 0; i < n; i++) {

    processes[i].PID = i;

    printf("Enter the Burst Time of %dth process: ", i);
    scanf("%d", &processes[i].burstTime);
  }

  printf("\nGantt Chart: ");

  bubbleSort(processes, n);

  getWaitingTime(processes, n);

  getTurnAroundTime(processes, n);

  printf("\n\nPID\tBT\tWT\tTAT\n");

  for (int i = 0; i < n; i++) {

    totalWaitingTime += processes[i].waitingTime;
    totalTurnAroundTime += processes[i].turnAroundTime;

    printf("P%d	", processes[i].PID);
    printf("%d	", processes[i].burstTime);

    printf("%d	", processes[i].waitingTime);
    printf("%d	\n", processes[i].turnAroundTime);
  }

  printf("\nAverage WaitingTime: %f", (float)totalWaitingTime / (float)n);
  printf("\nAverage TurnAroundTime: %f", (float)totalTurnAroundTime / (float)n);

  printf("\n\n");

  return 0;
}