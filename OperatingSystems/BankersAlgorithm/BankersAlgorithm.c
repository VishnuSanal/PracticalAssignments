#include <stdbool.h>
#include <stdio.h>

bool safetyAlgorithm(int n, int m, int alloc[n][m], int max[n][m],
                     int need[n][m], int avail[m], bool isResourceRequest) {

  int sequence[n], index = 0;

  bool visited[n];

  for (int i = 0; i < n; i++)
    visited[i] = false;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {

      if (visited[j] == true)
        continue;

      bool flag = true;

      for (int k = 0; k < m; k++)
        if (need[j][k] > avail[k]) {
          flag = false;
          break;
        }

      if (flag == true) {

        sequence[index++] = j;

        for (int k = 0; k < m; k++)
          avail[k] += alloc[j][k];

        visited[j] = true;
      }
    }

  for (int i = 0; i < n; i++)
    if (visited[i] == false) {

      printf("\nSystem not SAFE\n");

      if (isResourceRequest)
        printf(" => New request can't be allocated");

      return false;
    }

  printf("\nSAFE Sequence: ");

  for (int i = 0; i < n; i++)
    printf("P%d =>\t", sequence[i]);

  if (isResourceRequest)
    printf("\n => New request can be allocated");

  return true;
}

void resourceRequestAlgorithm(int n, int m, int alloc[n][m], int max[n][m],
                              int need[n][m], int avail[m], int request[m],
                              int new) {

  for (int i = 0; i < m; i++) {
    if (request[i] > need[new][i]) {
      printf("\nInvalid request: Request > Need => New request can't be "
             "allocated");
      return;
    }

    if (request[i] > avail[i]) {
      printf("\nInvalid request: Request > Avail => New request can't be "
             "allocated");
      return;
    }
  }

  for (int i = 0; i < m; i++) {

    avail[i] -= request[i];

    alloc[new][i] += request[i];

    need[new][i] -= request[i];
  }

  safetyAlgorithm(n, m, alloc, max, need, avail, true);
}

int main() {

  int n = 0, m = 0;

  printf("Enter the number of processes (n): ");
  scanf("%d", &n);

  printf("Enter the number of resources (m): ");
  scanf("%d", &m);

  int alloc[n][m], max[n][m], avail[m], need[n][m], availCopy[m];

  printf("Enter the allocation matrix [n x m]:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &alloc[i][j]);

  printf("Enter the maximum matrix [n x m]:\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &max[i][j]);

  printf("Enter the avail matrix [1 x m]:\n");
  for (int i = 0; i < m; i++) {
    scanf("%d", &avail[i]);
    availCopy[i] = avail[i];
  }

  bool result = safetyAlgorithm(n, m, alloc, max, need, avail, false);

  if (!result)
    return 0;

  int new, request[m];

  printf("\n\nPID of the process requesting next: ");
  scanf("%d", &new);

  printf("Enter the need vector of the next request [1 x m]: ");
  for (int i = 0; i < m; i++)
    scanf("%d", &request[i]);

  resourceRequestAlgorithm(n, m, alloc, max, need, availCopy, request, new);

  printf("\n\n");

  return 0;
}