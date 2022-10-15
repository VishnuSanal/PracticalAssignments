#include <stdio.h>

struct Process {

  int PID;
  int arrivalTime;
  int burstTime;
  int waitingTime;
  int turnAroundTime;

  int startTime;
  int endTime;
};

void getWaitingTime(struct Process processes[], int n) {

  processes[0].waitingTime = processes[0].startTime = 0;

  for (int i = 1; i < n; i++) {

    processes[i].startTime =
        processes[i - 1].startTime + processes[i - 1].burstTime;

    processes[i].waitingTime =
        processes[i].startTime - processes[i].arrivalTime;
  }
}

void getTurnAroundTime(struct Process processes[], int n) {

  processes[0].endTime = processes[0].turnAroundTime = processes[0].burstTime;

  for (int i = 1; i < n; i++) {

    processes[i].endTime = processes[i - 1].endTime + processes[i].burstTime;

    processes[i].turnAroundTime =
        processes[i].endTime - processes[i].arrivalTime;
  }
}

void swap(struct Process *a, struct Process *b) {
  struct Process temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(struct Process processes[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (processes[j].arrivalTime > processes[j + 1].arrivalTime)
        swap(&processes[j], &processes[j + 1]);
}

int main() {

  int n = 0, totalWaitingTime = 0, totalTurnAroundTime = 0;

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  struct Process processes[n];

  for (int i = 0; i < n; i++) {

    processes[i].PID = i;

    printf("Enter the Arrival Time of %dth process: ", i);
    scanf("%d", &processes[i].arrivalTime);

    printf("Enter the Burst Time of %dth process: ", i);
    scanf("%d", &processes[i].burstTime);
  }

  bubbleSort(processes, n);

  getWaitingTime(processes, n);

  getTurnAroundTime(processes, n);

  printf("\n\nGantt Chart: ");

  for (int i = 0; i < n; i++)
    printf("[%d P%d %d]\t", processes[i].startTime, processes[i].PID,
           processes[i].endTime);

  printf("\n\nPID\tAT\tBT\tST\tET\tWT\tTAT\n");

  for (int i = 0; i < n; i++) {

    totalWaitingTime += processes[i].waitingTime;
    totalTurnAroundTime += processes[i].turnAroundTime;

    printf("P%d	", processes[i].PID);
    printf("%d	", processes[i].arrivalTime);
    printf("%d	", processes[i].burstTime);

    printf("%d	", processes[i].startTime);
    printf("%d	", processes[i].endTime);

    printf("%d	", processes[i].waitingTime);
    printf("%d	\n", processes[i].turnAroundTime);
  }

  printf("\nAverage WaitingTime: %f", (float)totalWaitingTime / (float)n);
  printf("\nAverage TurnAroundTime: %f", (float)totalTurnAroundTime / (float)n);

  printf("\n\n");

  return 0;
}
