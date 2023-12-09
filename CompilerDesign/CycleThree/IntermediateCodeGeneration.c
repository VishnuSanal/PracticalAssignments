#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char STACK[MAX];
int TOP = -1;

void push(char c) { STACK[++TOP] = c; }
char pop() { return STACK[TOP--]; }

int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
  int j = 0;
  for (int i = 0; infix[i]; i++)
    if (isalnum(infix[i]))
      postfix[j++] = infix[i];
    else if (infix[i] == '(')
      push(infix[i]);
    else if (infix[i] == ')') {
      while (STACK[TOP] != '(')
        postfix[j++] = pop();
      pop();
    } else {
      while (priority(STACK[TOP]) >= priority(infix[i]))
        postfix[j++] = pop();
      push(infix[i]);
    }
  while (TOP >= 0)
    postfix[j++] = pop();
  postfix[j] = '\0';
}

void generateThreeAddressCode(char *str) {
  TOP = -1;
  int t1 = 90;
  char t2, t3;
  for (int i = 0; i < strlen(str); i++) {
    if (isalnum(str[i])) {
      push(str[i]);
    } else {
      t3 = pop();
      t2 = pop();
      printf("%c := %c %c %c\n", t1, t2, str[i], t3);
      push(t1--);
    }
  }
}

int main() {
  char infix[MAX], postfix[MAX];

  printf("\nEnter a simple expression: ");
  scanf("%s", infix);

  printf("\nThree Address Code:\n\n");

  infixToPostfix(infix, postfix);

  generateThreeAddressCode(postfix);

  printf("\n\n");

  return 0;
}
