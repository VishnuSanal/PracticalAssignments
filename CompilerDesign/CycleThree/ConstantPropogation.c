#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expression {
  char operator[2], operandOne[5], operandTwo[5], result[5];
  bool flag;
} expressions[10];

int numberOfExpressions;

void copyValues(int l, char *result) {
  for (int i = l + 1; i < numberOfExpressions; i++) {
    if (strcmp(expressions[l].result, expressions[i].operandOne) == 0)
      strcpy(expressions[i].operandOne, result);
    if (strcmp(expressions[l].result, expressions[i].operandTwo) == 0)
      strcpy(expressions[i].operandTwo, result);
  }
}

void constant() {
  int res;
  char res1[5];

  for (int i = 0; i < numberOfExpressions; i++) {
    if (isdigit(expressions[i].operandOne[0]) &&
            isdigit(expressions[i].operandTwo[0]) ||
        strcmp(expressions[i].operator, "=") == 0) {
      int operandOne = atoi(expressions[i].operandOne);
      int operandTwo = atoi(expressions[i].operandTwo);
      char operator= expressions[i].operator[0];
      switch (operator) {
      case '+':
        res = operandOne + operandTwo;
        break;
      case '-':
        res = operandOne - operandTwo;
        break;
      case '*':
        res = operandOne * operandTwo;
        break;
      case '/':
        res = operandOne / operandTwo;
        break;
      case '=':
        res = operandOne;
        break;
      }
      sprintf(res1, "%d", res);
      expressions[i].flag = true;
      copyValues(i, res1);
    }
  }
}

int main() {

  printf("\nNumber of expressions: ");
  scanf("%d", &numberOfExpressions);

  printf("\nEnter the input:\n\n");
  for (int i = 0; i < numberOfExpressions; i++) {
    scanf("%s %s %s %s", expressions[i].operator, expressions[i].operandOne,
          expressions[i].operandTwo, expressions[i].result);
    expressions[i].flag = false;
  }

  constant();

  printf("\nOptimized Code:\n");
  for (int i = 0; i < numberOfExpressions; i++) {
    if (!expressions[i].flag) {
      printf("\n%s %s %s %s", expressions[i].operator,
             expressions[i].operandOne, expressions[i].operandTwo,
             expressions[i].result);
    }
  }

  printf("\n\n");
  return 0;
}
