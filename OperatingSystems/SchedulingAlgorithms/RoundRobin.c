#include <stdbool.h>
#include <stdio.h>

struct Process {
  int PID;

  int burstTime;

  int waitingTime;
  int turnAroundTime;
};

void getWaitingTime(struct Process processes[], int quantum, int n) {

  int currentTime = 0;

  int remainingBurstTime[n];

  for (int i = 0; i < n; i++)
    remainingBurstTime[i] = processes[i].burstTime;

  while (true) {

    bool completed = true;

    for (int i = 0; i < n; i++) {

      if (remainingBurstTime[i] <= 0)
        continue;

      completed = false;

      int prevTime = currentTime;

      if (remainingBurstTime[i] > quantum) {

        remainingBurstTime[i] -= quantum;
        currentTime += quantum;
      } else {

        currentTime += remainingBurstTime[i];
        remainingBurstTime[i] = 0;

        processes[i].waitingTime = currentTime - processes[i].burstTime;
      }

      printf(" [ %d P%d %d ]", prevTime, processes[i].PID, currentTime);
    }

    if (completed == true)
      break;
  }
}

void getTurnAroundTime(struct Process processes[], int n) {
  for (int i = 0; i < n; i++)
    processes[i].turnAroundTime =
        processes[i].burstTime + processes[i].waitingTime;
}

int main() {

  int n = 0, totalWaitingTime = 0, totalTurnAroundTime = 0, quantum = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {

      processes[i].PID = i;

      printf("Enter the Burst Time of %dth process: ", i);
      scanf("%d", &processes[i].burstTime);
    }

  getWaitingTime(processes, quantum, n);

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
