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
#include <string.h>

char expression[10];
int idx = 0;
bool error = false;

void E(), T(), EPrime(), TPrime(), F();

int main() {

  printf("\n-Recursive Precedence Parser for Simple Desk Calculator-\n");

  printf("\nEnter an arithmetic expression: ");
  scanf("%s", expression);

  E();

  if (strlen(expression) == idx && !error)
    printf("String accepted\n");
  else
    printf("String rejected\n");
}

void E() {
  T();

  EPrime();
}

void EPrime() {
  if (expression[idx] == '+' || expression[idx] == '-') {
    idx++;

    T();

    EPrime();
  }
}

void T() {
  F();

  TPrime();
}

void TPrime() {
  if (expression[idx] == '*' || expression[idx] == '/') {
    idx++;

    F();

    TPrime();
  }
}

void F() {
  if (isalnum(expression[idx]))
    idx++;
  else if (expression[idx] == '(') {
    idx++;

    E();

    if (expression[idx] == ')')
      idx++;
    else
      error = true;

  } else
    error = true;
}

