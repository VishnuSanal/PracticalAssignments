#include <stdbool.h>
#include <stdio.h>

#define MAX 5

int QUEUE[MAX], FRONT = -1, REAR = -1;

void enqueue();
void dequeue();
void display();
void peek();
bool isFull();
bool isEmpty();

int main() {

  int choice;
  printf("Menu\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit\n");

  while (true) {

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...");
      return 0;
    default:
      printf("Invalid choice");
    }
  }

  return 0;
}

bool isFull() { return (REAR + 1) % MAX == FRONT; }

bool isEmpty() { return FRONT < 0 && REAR < 0; }

void peek() {

  if (isEmpty()) {
    printf("Queue Empty");
    return;
  }

  printf("Front element is: %d", QUEUE[FRONT]);
}

void enqueue() {

  if (isFull()) {
    printf("Queue Overflow");
    return;
  }

  int x;
  printf("Enter Element: ");
  scanf("%d", &x);

  if (isEmpty())
    FRONT = REAR = 0;
  else
    REAR = (REAR + 1) % MAX;

  QUEUE[REAR] = x;
}

void dequeue() {

  if (isEmpty()) {
    printf("Queue Underflow");
    return;
  }

  int v = QUEUE[FRONT];

  if (FRONT == REAR)
    FRONT = REAR = -1;
  else
    FRONT = (FRONT + 1) % MAX;

  printf("Removed element: %d", v);
}

void display() {

  if (isEmpty()) {
    printf("Queue Empty");
    return;
  }

  int i;

  for (i = FRONT; i != REAR; i = (i + 1) % MAX)
    printf("%d ", QUEUE[i]);

  printf("\t%d", QUEUE[i]);
}
