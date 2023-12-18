// E -> E + T | E - T | T
// T -> E * F | E / F | F
// F -> ( E ) | alnum

// removing left recursion...

// E ->  TE'
// E' -> +TE' | -TE' | epsilon
// T  -> FT'
// T' -> *FT' | /FT' | epsilon
// F  -> (E)  | alnum

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

char expression[100], *lookahead;

bool error = false;

void E(), EPrime(), T(), TPrime(), F();

int main() {

  printf("\n-Recursive Precedence Parser for Simple Desk Calculator-\n");

  printf("\nEnter an arithmetic expression: ");
  scanf("%s", expression);

  lookahead = expression;

  E();

  if (*lookahead == '\0' && !error)
    printf("String accepted\n");
  else
    printf("String rejected\n");

  return 0;
}

void E() {
  T();
  EPrime();
}

void EPrime() {
  if (*lookahead == '+' || *lookahead == '-') {
    lookahead++;

    T();
    EPrime();
  }
}

void T() {
  F();
  TPrime();
}

void TPrime() {
  if (*lookahead == '*' || *lookahead == '/') {
    lookahead++;

    F();
    TPrime();
  }
}

void F() {
  if (isalnum(*lookahead))
    lookahead++;
  else if (*lookahead == '(') {
    lookahead++;

    E();

    if (*lookahead == ')')
      lookahead++;
    else
      error = true;
  } else
    error = true;
}
