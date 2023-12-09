#include <stdio.h>
#include <string.h>

int inputIdx = 0;

char input[16], STACK[15];

void check();

int main() {
  printf("\nGrammar: E -> E + E | E * E | (E) | id");

  printf("\n\nEnter the input string: ");
  scanf("%s", input);

  printf("\nStack\t\tInput\tAction\n");
  for (int i = 0; inputIdx < strlen(input); i++, inputIdx++) {
    if (input[inputIdx] == 'i' && input[inputIdx + 1] == 'd') {
      STACK[i] = input[inputIdx];
      STACK[i + 1] = input[inputIdx + 1];
      STACK[i + 2] = '\0';
      input[inputIdx] = ' ';
      input[inputIdx + 1] = ' ';
      printf("\n$%s\t%s$\tSHIFT: id", STACK, input);
      check();
    } else {
      STACK[i] = input[inputIdx];
      STACK[i + 1] = '\0';
      input[inputIdx] = ' ';
      printf("\n$%s\t%s$\tSHIFT: %c", STACK, input, STACK[i]);
      check();
    }
  }

  if (inputIdx == strlen(input) && strlen(STACK) == 1 && STACK[0] == 'E')
    printf("\n\nString accepted");
  else
    printf("\n\nString rejected");

  printf("\n\n");
}

void check() {

  for (int i = 0; i <= strlen(input); i++)
    if (STACK[i] == 'i' && STACK[i + 1] == 'd') {
      STACK[i] = 'E';
      STACK[i + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE E", STACK, input);
      inputIdx++;
    }

  for (int i = 0; i <= strlen(input); i++)
    if (STACK[i] == 'E' && STACK[i + 1] == '+' && STACK[i + 2] == 'E') {
      STACK[i] = 'E';
      STACK[i + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE E", STACK, input);
    }

  for (int i = 0; i <= strlen(input); i++)
    if (STACK[i] == 'E' && STACK[i + 1] == '*' && STACK[i + 2] == 'E') {
      STACK[i] = 'E';
      STACK[i + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE E", STACK, input);
    }

  for (int i = 0; i <= strlen(input); i++)
    if (STACK[i] == '(' && STACK[i + 1] == 'E' && STACK[i + 2] == ')') {
      STACK[i] = 'E';
      STACK[i + 1] = '\0';
      printf("\n$%s\t%s$\tREDUCE E", STACK, input);
    }
}