#include <stdio.h>

struct node {
  unsigned dist[20];
  unsigned from[20];
} routingTable[10];

int main() {

  int costMatrix[20][20];

  int nodes, count = 0;

  printf("\nNumber of routers: ");
  scanf("%d", &nodes);

  printf("\nCost matrix:\n\n");
  for (int i = 0; i < nodes; i++)
    for (int j = 0; j < nodes; j++) {
      scanf("%d", &costMatrix[i][j]);

      costMatrix[i][i] = 0;

      routingTable[i].dist[j] = costMatrix[i][j];
      routingTable[i].from[j] = j;
    }
  do {
    count = 0;
    for (int i = 0; i < nodes; i++)
      for (int j = 0; j < nodes; j++)
        for (int k = 0; k < nodes; k++)

          if (routingTable[i].dist[j] >
              costMatrix[i][k] + routingTable[k].dist[j]) {

            routingTable[i].dist[j] =
                costMatrix[i][k] + routingTable[k].dist[j];
            routingTable[i].from[j] = k;

            count++;
          }

  } while (count != 0);

  for (int i = 0; i < nodes; i++) {
    printf("\n\nRouter %d: ", i + 1);
    printf("\nDEST\tNEXTHOP\tDIST");

    for (int j = 0; j < nodes; j++)
      printf("\n%d\t%d\t%d", j + 1, routingTable[i].from[j] + 1,
             routingTable[i].dist[j]);
  }

  printf("\n\n");
}

/*
0  2 99 1
2  0 3  7
99 3 0  11
1  7 11 0
*/

/*
0 1 5
1 0 2
5 2 0
*/
