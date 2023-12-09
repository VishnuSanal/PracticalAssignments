#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 26

struct state {
  char stateName[20];
} stateList[30];

int numberOfTransitions, numberOfFinalStates, symbolsLength, stateIndex = 0,
                                                             currentState = 0;

char startState, transitionsNFA[20][3], finalStates[20], symbols[10];

bool stateEquals(const char *one, const char *two) {
  int frequencyOne[MAX_CHARS] = {0}, frequencyTwo[MAX_CHARS] = {0};

  if (strlen(one) != strlen(two))
    return false;

  for (int i = 0; i < strlen(one); i++) {
    frequencyOne[one[i] - 'a']++;
    frequencyTwo[two[i] - 'a']++;
  }

  for (int i = 0; i < MAX_CHARS; i++)
    if (frequencyOne[i] != frequencyTwo[i])
      return false;

  return true;
}

bool haveCommonCharacters(const char *one, const char *two) {
  int frequencyOne[MAX_CHARS] = {0};
  int frequencyTwo[MAX_CHARS] = {0};

  for (int i = 0; i < strlen(one); i++)
    frequencyOne[one[i] - 'a']++;

  for (int i = 0; i < strlen(two); i++)
    frequencyTwo[two[i] - 'a']++;

  for (int i = 0; i < MAX_CHARS; i++)
    if (frequencyOne[i] > 0 && frequencyTwo[i] > 0)
      return true;

  return false;
}

bool isState(char *s) {
  for (int i = 0; i < stateIndex; i++)
    if (stateEquals(stateList[i].stateName, s))
      return true;
  return false;
}

bool contains(char *str, char c) {
  for (int i = 0; i < strlen(str); i++)
    if (str[i] == c)
      return true;
  return false;
}

void convertDFA() {
  char state[20] = {'\0'};
  bool containsDeadState = false;
  int idx = 0;

  printf("\nResult DFA transition table:\nstate symbol state\n");

  while (stateIndex != currentState) {
    for (int i = 0; i < symbolsLength; i++) {
      for (int k = 0; k < strlen(stateList[currentState].stateName); k++)
        for (int j = 0; j < numberOfTransitions; j++)
          if (stateList[currentState].stateName[k] == transitionsNFA[j][0] &&
              transitionsNFA[j][1] == symbols[i])
            if (!contains(state, transitionsNFA[j][2])) {
              state[idx] = transitionsNFA[j][2];
              state[++idx] = '\0';
            }
      if (idx == false) {
        printf("\n%s\t%c\tDead", stateList[currentState].stateName, symbols[i]);
        containsDeadState = true;
      } else {
        printf("\n%s\t%c\t%s", stateList[currentState].stateName, symbols[i],
               state);
        if (!isState(state))
          strcpy(stateList[stateIndex++].stateName, state);
      }
      idx = 0;
      state[idx] = '\0';
    }
    currentState++;
  }
  if (containsDeadState)
    for (int i = 0; i < symbolsLength; i++)
      printf("\nDead\t%c\tDead", symbols[i]);
}

void printFinalStates() {
  printf("\n\nFinal states: { ");
  for (int i = 0; i < stateIndex; i++)
    if (haveCommonCharacters(finalStates, stateList[i].stateName))
      printf("%s, ", stateList[i].stateName);
  printf("}");
}

int main() {
  printf("Number of transitions: ");
  scanf("%d", &numberOfTransitions);

  printf("Number of final states: ");
  scanf("%d", &numberOfFinalStates);

  printf("Start state: ");
  scanf(" %c", &startState);

  printf("Final states: ");
  scanf("%s", finalStates);

  printf("Symbols: ");
  scanf("%s", symbols);

  printf("Transitions:\nstate symbol state\n");
  for (int i = 0; i < numberOfTransitions; i++)
    scanf(" %c %c %c", &transitionsNFA[i][0], &transitionsNFA[i][1],
          &transitionsNFA[i][2]);

  symbolsLength = strlen(symbols);

  stateList[stateIndex].stateName[0] = startState;
  stateList[stateIndex].stateName[1] = '\0';
  stateIndex++;

  convertDFA();

  printFinalStates();

  printf("\n\n");
}