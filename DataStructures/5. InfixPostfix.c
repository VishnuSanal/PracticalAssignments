#include <ctype.h>
#include <stdio.h>

char STACK[100];
int TOP = -1;

void convertPostFix(char[]);
int priority(char);
void push(char);
char pop();

int main() {

  char expression[100];

  printf("\nEnter a valid infix expression: ");
  scanf("%s", expression);

  printf("\n");

  convertPostFix(expression);

  printf("\n\n");

  return 0;
}

void convertPostFix(char expression[]) {

  char *e = expression, x;

  while (*e != '\0') {

    if (isalnum(*e))
      printf("%c ", *e);
    else if (*e == '(')
      push(*e);
    else if (*e == ')')
      while ((x = pop()) != '(')
        printf("%c ", x);
    else {
      while (priority(STACK[TOP]) >= priority(*e))
        printf("%c ", pop());
      push(*e);
    }

    e++;
  }

  while (TOP != -1)
    printf("%c ", pop());
}

int priority(char x) {
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  if (x == '^')
    return 3;
  return 0;
}

void push(char c) { STACK[++TOP] = c; }

char pop() { return STACK[TOP--]; }
