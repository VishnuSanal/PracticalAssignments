#include <ctype.h>
#include <stdio.h>
#include <string.h>

int numberOfProductions, idx = 0;

char productions[10][10], result[10];

void calculateFirst(char c) {

  // necessary for the case to calculate first whilst calculating follow
  if (!isupper(c))
    result[idx++] = c;

  for (int i = 0; i < numberOfProductions; i++) {
    if (productions[i][0] != c)
      continue;

    if (islower(productions[i][2]))
      result[idx++] = productions[i][2];
    else
      calculateFirst(productions[i][2]);
  }
}

void calculateFollow(char c) {

  if (productions[0][0] == c)
    result[idx++] = '$';

  for (int i = 0; i < numberOfProductions; i++)
    for (int j = 2; j < strlen(productions[i]); j++) {

      if (productions[i][j] != c)
        continue;

      if (productions[i][j + 1])
        calculateFirst(productions[i][j + 1]);
      else if (productions[i][0] != c)
        calculateFollow(productions[i][0]);
    }
}

void print(char *s, char symbol, char *str) {

  printf("\n%s(%c): ", s, symbol);

  for (int i = 0; str[i]; i++) {
    printf("%c ", str[i]);
  }
}

int main() {

  printf("Productions: ");
  scanf("%d", &numberOfProductions);

  for (int i = 0; i < numberOfProductions; i++) {
    scanf("%s", productions[i]);
    getchar();
  }

  for (int i = 0; i < numberOfProductions; i++) {

    idx = 0;
    strcpy(result, "");

    calculateFirst(productions[i][0]);

    print("First", productions[i][0], result);
  }

  printf("\n\n");

  for (int i = 0; i < numberOfProductions; i++) {

    idx = 0;
    strcpy(result, "");

    calculateFollow(productions[i][0]);

    print("Follow", productions[i][0], result);
  }

  printf("\n\n");

  return 0;
}
