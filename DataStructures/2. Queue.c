#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue();
void dequeue();
void display();
bool isFull();
bool isEmpty();

int QUEUE[MAX], REAR = -1, FRONT = -1;

int main() {

  int choice;

  printf("\nMenu\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");

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
      display();
      break;
    case 4:
      printf("Exiting...");
      exit(1);
    default:
      printf("Invalid choice");
    }
  }

  return 0;
}

bool isFull() { return REAR == MAX - 1; }

bool isEmpty() { return FRONT == -1; }

void enqueue() {

  if (isFull()) {
    printf("Queue Overflow");
    return;
  }

  if (FRONT == -1)
    FRONT++;

  int x;
  printf("Enter Element: ");
  scanf("%d", &x);

  QUEUE[++REAR] = x;
}

void dequeue() {

  if (isEmpty()) {
    printf("Queue Underflow");
    return;
  }

  printf("Element deleted: %d", QUEUE[FRONT++]);

  if (FRONT > REAR)
    FRONT = REAR = -1;
}

void display() {

  if (isEmpty()) {
    printf("Queue Empty");
    return;
  }

  for (int i = FRONT; i <= REAR; i++)
    printf("\t%d", QUEUE[i]);
}

