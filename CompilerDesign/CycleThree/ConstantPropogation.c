#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expression {
  char operator[2], operandOne[5], operandTwo[5], result[5];
  bool isRemoved;
} expressions[10];

int numberOfExpressions;

void propogateConstants(int current, int result) {
  char resultCopy[5];

  sprintf(resultCopy, "%d", result);

  for (int i = current + 1; i < numberOfExpressions; i++) {
    if (strcmp(expressions[current].result, expressions[i].operandOne) == 0)
      strcpy(expressions[i].operandOne, resultCopy);
    if (strcmp(expressions[current].result, expressions[i].operandTwo) == 0)
      strcpy(expressions[i].operandTwo, resultCopy);
  }
}

void scanQuadruples() {
  int result;

  for (int i = 0; i < numberOfExpressions; i++) {
    if (isdigit(expressions[i].operandOne[0]) &&
            isdigit(expressions[i].operandTwo[0]) ||
        strcmp(expressions[i].operator, "=") == 0) {

      int operandOne = atoi(expressions[i].operandOne);
      int operandTwo = atoi(expressions[i].operandTwo);

      char operator= expressions[i].operator[0];

      switch (operator) {
      case '+':
        result = operandOne + operandTwo;
        break;
      case '-':
        result = operandOne - operandTwo;
        break;
      case '*':
        result = operandOne * operandTwo;
        break;
      case '/':
        result = operandOne / operandTwo;
        break;
      case '=':
        result = operandOne;
        break;
      }

      expressions[i].isRemoved = true;
      propogateConstants(i, result);
    }
  }
}

int main() {

  printf("\nNumber of expressions: ");
  scanf("%d", &numberOfExpressions);

  printf("\nEnter the input (quadruples):\n\n");
  for (int i = 0; i < numberOfExpressions; i++) {
    scanf("%s %s %s %s", expressions[i].operator, expressions[i].operandOne,
          expressions[i].operandTwo, expressions[i].result);
    expressions[i].isRemoved = false;
  }

  scanQuadruples();

  printf("\nOptimized Code:\n");
  for (int i = 0; i < numberOfExpressions; i++) {
    if (!expressions[i].isRemoved)
      printf("\n%s %s %s %s", expressions[i].operator,
             expressions[i].operandOne, expressions[i].operandTwo,
             expressions[i].result);
  }

  printf("\n\n");
  return 0;
}
