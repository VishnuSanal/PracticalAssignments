#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Vertex {
  char label;
  bool visited;
};

int STACK[MAX], TOP = -1;

int QUEUE[MAX], REAR = -1, FRONT = 0, queueItemCount = 0;

struct Vertex *vertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

void breadthFirstSearch();
void depthFirstSearch();

void addVertex(char);
void addEdge(int, int);
void displayVertex(int);
int getAdjUnvisitedVertex(int);

void enqueue(int);
int dequeue();
bool isQueueEmpty();

void push(int);
int pop();
int isStackEmpty();

int main() {

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++)
      adjMatrix[i][j] = 0;
  }

  int vertices, edges;

  printf("\nEnter number of vertices (max 10): ");
  scanf("%d", &vertices);

  for (int i = 0; i < vertices; i++) {
    char var;

    printf("\nInsert %dth vertex label: ", i + 1);
    scanf("\t%c", &var);

    addVertex(var);
  }

  printf("\nEnter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++) {

    int initial, terminal;

    printf("\nSet %dth edge\n", i + 1);

    printf("Initial point: ");
    scanf("%d", &initial);

    printf("Terminal point: ");
    scanf("%d", &terminal);

    addEdge(initial, terminal);
  }

  printf("\nAdjacency matrix:\n");
  for (int i = 0; i < vertexCount; i++) {
    for (int j = 0; j < vertexCount; j++)
      printf("\t%d", adjMatrix[i][j]);
    printf("\n");
  }

  printf("\nBreadth First Search:\t");
  breadthFirstSearch();

  printf("\nDepth First Search:\t");
  depthFirstSearch();

  printf("\n\n");

  return 0;
}

void breadthFirstSearch() {

  vertices[0]->visited = true;

  displayVertex(0);
  enqueue(0);

  int unvisitedVertex;

  while (!isQueueEmpty()) {

    int tempVertex = dequeue();

    while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
      vertices[unvisitedVertex]->visited = true;
      displayVertex(unvisitedVertex);
      enqueue(unvisitedVertex);
    }
  }

  for (int i = 0; i < vertexCount; i++) {
    vertices[i]->visited = false;
  }
}

void depthFirstSearch() {

  int vertex = 0;

  push(vertex);

  while (!isStackEmpty()) {

    vertex = pop();

    if (!vertices[vertex]->visited) {
      printf("%c\t", vertices[vertex]->label);
      vertices[vertex]->visited = true;
    }

    for (int count = vertexCount - 1; count >= 0; count--) {
      if (adjMatrix[vertex][count] == 1 && !vertices[count]->visited) {
        push(count);
      }
    }
  }
}

void addVertex(char label) {
  struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
  vertex->label = label;
  vertex->visited = false;
  vertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
  adjMatrix[start][end] = 1;
  adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
  printf("\t%c", vertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex) {

  for (int i = 0; i < vertexCount; i++)
    if (adjMatrix[vertexIndex][i] == 1 && vertices[i]->visited == false)
      return i;

  return -1;
}

void enqueue(int val) {
  QUEUE[++REAR] = val;
  queueItemCount++;
}

int dequeue() {
  queueItemCount--;
  return QUEUE[FRONT++];
}

bool isQueueEmpty() { return queueItemCount == 0; }

void push(int val) { STACK[++TOP] = val; }

int pop() { return STACK[TOP--]; }

int isStackEmpty() { return TOP == -1; }
