#include <ctype.h>
#include <stdio.h>
#include <string.h>

int numberOfProductions, idx;

char production[10][10], result[10];

void calculateFirst(char c) {
  if (!isupper(c))
    result[idx++] = c;
  for (int k = 0; k < numberOfProductions; k++)
    if (production[k][0] == c) {
      if (islower(production[k][2]))
        result[idx++] = production[k][2];
      else
        calculateFirst(production[k][2]);
    }
}

void calculateFollow(char c) {
  if (production[0][0] == c)
    result[idx++] = '$';

  for (int i = 0; i < numberOfProductions; i++)
    for (int j = 2; j < strlen(production[i]); j++)
      if (production[i][j] == c) {
        if (production[i][j + 1] != '\0')
          calculateFirst(production[i][j + 1]);
        if (production[i][j + 1] == '\0' && c != production[i][0])
          calculateFollow(production[i][0]);
      }
}

void printResult(char *s, char state, char *result, int idx) {
  printf("%s(%c) = { ", s, state);
  for (int i = 0; i < idx; i++)
    printf("%c ", result[i]);

  printf("}\n");
}

int main() {
  printf("Number of productions: ");
  scanf("%d", &numberOfProductions);

  printf("\nEnter the productions:\n");
  for (int i = 0; i < numberOfProductions; i++) {
    scanf("%s", production[i]);
    getchar();
  }

  for (int i = 0; i < numberOfProductions; i++) {

    char state = production[i][0];

    idx = 0;

    calculateFirst(state);

    printResult("First", state, result, idx);

    strcpy(result, " ");
    idx = 0;

    calculateFollow(state);

    printResult("Follow", state, result, idx);

    printf("\n\n");
  }

  return 0;
}