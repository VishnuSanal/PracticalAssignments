#include <stdbool.h>
#include <stdio.h>

int MAX, TOP = -1, STACK[100];

void push();
void pop();
void display();
bool isFull();
bool isEmpty();

int main() {

  int choice;

  printf("Enter the size of stack (max 100): ");
  scanf("%d", &MAX);

  printf("\nMenu\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit\n\n");

  do {

    printf("\nEnter a choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Exiting...");
      return 0;
    default:
      printf("Invalid choice");
    }
  } while (choice != 4);

  return 0;
}

bool isFull() { return TOP >= MAX - 1; }

bool isEmpty() { return TOP < 0; }

void push() {

  if (isFull()) {

    printf("Stack Overflow");
    return;
  }

  int i;
  printf("Enter the number to push: ");
  scanf("%d", &i);
  STACK[++TOP] = i;
}

void pop() {

  if (isEmpty()) {
    printf("Stack Underflow");
    return;
  }

  printf("\nThe popped number is: %d", STACK[TOP--]);
}

void display() {

  if (TOP < 0) {

    printf("Stack Empty");
    return;
  }

  printf("\nPrinting Stack:\n");
  for (int i = TOP; i >= 0; i--)
    printf("\t%d", STACK[i]);

  printf("\n");
}

