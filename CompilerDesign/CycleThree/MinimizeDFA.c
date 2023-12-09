#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STATES 99
#define SYMBOLS 20

int numberOfSymbols, numberOfStates, outputNumberOfStates,
    inputDFA[STATES][SYMBOLS], outputDFA[STATES][SYMBOLS];

char finalStates[20], stateNames[STATES][STATES + 1],
    outputFinalStates[STATES + 1];

void printTransitionTable(int DFA[][SYMBOLS], int numberOfStates,
                          int numberOfSymbols, char *finalState) {

  puts("DFA: STATE TRANSITION TABLE");
  printf("     | ");

  for (int i = 0; i < numberOfSymbols; i++)
    printf("  %c  ", '0' + i);

  printf("\n-----+--");
  for (int i = 0; i < numberOfSymbols; i++)
    printf("-----");

  printf("\n");
  for (int i = 0; i < numberOfStates; i++) {
    printf("  %c  | ", 'A' + i);

    for (int j = 0; j < numberOfSymbols; j++)
      printf("  %c  ", DFA[i][j]);
    printf("\n");
  }

  printf("Final states: %s\n", finalState);
}

void getNextState(char *nextStates, char *currentStates,
                  int DFA[STATES][SYMBOLS], int symbol) {
  for (int i = 0; i < strlen(currentStates); i++)
    *nextStates++ = DFA[currentStates[i] - 'A'][symbol];
  *nextStates = '\0';
}

char equivalentClassIndex(char ch, char stnt[][STATES + 1], int n) {
  for (int i = 0; i < n; i++)
    if (strchr(stnt[i], ch))
      return i + '0';
  return -1;
}

char isOneNextState(char *s) {
  while (*s == '@')
    s++;
  char equiv_class = *s++;
  while (*s) {
    if (*s != '@' && *s != equiv_class)
      return 0;
    s++;
  }
  return equiv_class;
}

int stateIndex(char *state, char stateNames[][STATES + 1], int n, int *pn,
               int current) {
  int i;
  char state_flags[STATES + 1];

  if (!*state)
    return -1;

  for (i = 0; i < strlen(state); i++)
    state_flags[i] = equivalentClassIndex(state[i], stateNames, n);
  state_flags[i] = '\0';

  if ((i = isOneNextState(state_flags)))
    return i - '0';
  else {
    strcpy(stateNames[*pn], state_flags);
    return (*pn)++;
  }
}

int initEquivalentClass(char stateNames[][STATES + 1], int numberOfStates,
                        char *finalStates) {
  if (strlen(finalStates) == numberOfStates) {
    strcpy(stateNames[0], finalStates);
    return 1;
  }

  int j = 0;
  strcpy(stateNames[1], finalStates);
  for (int i = 0; i < numberOfStates; i++) {
    if (i == *finalStates - 'A')
      finalStates++;
    else
      stateNames[0][j++] = i + 'A';
  }
  stateNames[0][j] = '\0';
  return 2;
}

int getOptimizedDFA(char stateNames[][STATES + 1], int n,
                    int inputDFA[][SYMBOLS], int numberOfSymbols,
                    int resultDFA[][SYMBOLS]) {
  int result = n;
  char nextstate[STATES + 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < numberOfSymbols; j++) {
      getNextState(nextstate, stateNames[i], inputDFA, j);
      resultDFA[i][j] = stateIndex(nextstate, stateNames, n, &result, i) + 'A';
    }
  }
  return result;
}

void append(char *s, char ch) {
  int n = strlen(s);
  *(s + n) = ch;
  *(s + n + 1) = '\0';
}

void sort(char stateNames[][STATES + 1], int n) {
  char temp[STATES + 1];
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (stateNames[i][0] > stateNames[j][0]) {
        strcpy(temp, stateNames[i]);
        strcpy(stateNames[i], stateNames[j]);
        strcpy(stateNames[j], temp);
      }
}

int splitEquivalentClass(char stnt[][STATES + 1], int i1, int i2, int n,
                         int n_dfa) {
  char *old = stnt[i1], *vec = stnt[i2];
  int i, n2, flag = 0;
  char newstates[STATES][STATES + 1];
  for (i = 0; i < STATES; i++)
    newstates[i][0] = '\0';
  for (i = 0; vec[i]; i++)
    append(newstates[vec[i] - '0'], old[i]);
  for (i = 0, n2 = n; i < n_dfa; i++) {
    if (newstates[i][0]) {
      if (!flag) {
        strcpy(stnt[i1], newstates[i]);
        flag = 1;
      } else
        strcpy(stnt[n2++], newstates[i]);
    }
  }
  sort(stnt, n2);
  return n2;
}

int setNewEquivalentClass(char stateNames[][STATES + 1], int n,
                          int DFA[][SYMBOLS], int numberOfSymbols,
                          int numberOfStates) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < numberOfSymbols; j++) {
      int k = DFA[i][j] - 'A';
      if (k >= n)
        return splitEquivalentClass(stateNames, i, k, n, numberOfStates);
    }
  }
  return n;
}

int minimizeDFA(int inputDFA[][SYMBOLS], int numberOfStates,
                int numberOfSymbols, char *finalState,
                char stateNames[][STATES + 1], int resultDFA[][SYMBOLS]) {
  int n = initEquivalentClass(stateNames, numberOfStates, finalState);
  while (true) {
    int n2 =
        getOptimizedDFA(stateNames, n, inputDFA, numberOfSymbols, resultDFA);
    if (n != n2)
      n = setNewEquivalentClass(stateNames, n, resultDFA, numberOfSymbols,
                                numberOfStates);
    else
      break;
  }
  return n;
}

int isSubset(char *s, char *t) {
  for (int i = 0; *t; i++)
    if (!strchr(s, *t++))
      return 0;
  return 1;
}

void getFinalStates(char *newFinalStates, char *oldFinalStates,
                    char stateNames[][STATES + 1], int n) {
  for (int i = 0; i < n; i++)
    if (isSubset(oldFinalStates, stateNames[i]))
      *newFinalStates++ = i + 'A';
  *newFinalStates++ = '\0';
}

int main() {

  printf("Number of states: ");
  scanf("%d", &numberOfStates);

  printf("Number of symbols: ");
  scanf("%d", &numberOfSymbols);

  printf("Enter transitions\n");
  char c;
  for (int i = 0; i < numberOfStates; i++) {
    for (int j = 0; j < numberOfSymbols; j++) {
      printf("State %c upon input %d: ", i + 65, j);
      scanf("\n%c", &c);
      inputDFA[i][j] = c;
    }
  }

  printf("Final states (non-seperated): ");
  scanf("%s", finalStates);

  printTransitionTable(inputDFA, numberOfStates, numberOfSymbols, finalStates);

  outputNumberOfStates = minimizeDFA(inputDFA, numberOfStates, numberOfSymbols,
                                     finalStates, stateNames, outputDFA);

  getFinalStates(outputFinalStates, finalStates, stateNames,
                 outputNumberOfStates);

  printf("After minimization");
  printTransitionTable(outputDFA, outputNumberOfStates, numberOfSymbols,
                       outputFinalStates);
  return 0;
}
