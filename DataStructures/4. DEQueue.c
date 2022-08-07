#include <stdbool.h>
#include <stdio.h>

#define MAX 5

int QUEUE[MAX], REAR = -1, FRONT = -1;

void insertRear();
void deleteFront();
void deleteRear();
void insertFront();
void display();
bool isFull();
bool isEmpty();

int main() {

  int choice;

  printf("Menu:\n 1. Insert from Rear\n 2. Delete from Front\n 3. "
         "Insert from Front\n 4. Delete from Rear\n 5. Display\n 6. Exit\n");

  while (true) {

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
      insertRear();
      break;
    case 2:
      deleteFront();
      break;
    case 3:
      insertFront();
      break;
    case 4:
      deleteRear();
      break;
    case 5:
      display();
      break;
    case 6:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid choice");
    }
  }

  return 0;
}

bool isFull() { return REAR == MAX - 1; }

bool isEmpty() { return FRONT < 0; }

void insertRear() {

  int a;

  if (isFull()) {
    printf("Queue is full");
    return;
  }

  if (FRONT == -1)
    FRONT++;

  printf("Enter Element: ");
  scanf("%d", &a);

  QUEUE[++REAR] = a;
}

void deleteFront() {

  int value;

  if (isEmpty()) {
    printf("Queue Empty");
    return;
  }

  value = QUEUE[FRONT];

  if (REAR == FRONT)
    FRONT = REAR = -1;
  else
    FRONT++;

  printf("The deleted element from front is: %d", value);
}

void deleteRear() {

  int value;

  if (isEmpty()) {
    printf("Queue Empty");
    return;
  }

  value = QUEUE[REAR];

  if (REAR == FRONT)
    FRONT = REAR = -1;
  else
    REAR--;

  printf("The deleted element from rear is: %d", value);
}

void insertFront() {

  if (FRONT == 0) {
    printf("Front is at the beginning - insertion not possible");
    return;
  }

  if (FRONT == -1) {
    FRONT++;
    REAR++;
  } else
    FRONT--;

  int x;
  printf("Enter Element: ");
  scanf("%d", &x);

  QUEUE[FRONT] = x;
}

void display() {

  if (isEmpty()) {
    printf("Queue Empty");
    return;
  }

  printf("Printing DeQueue:\n");

  for (int i = FRONT; i <= REAR; i++)
    printf("\t%d", QUEUE[i]);
}
