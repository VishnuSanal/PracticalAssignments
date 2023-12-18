#include <stdbool.h>
#include <stdio.h>

bool hasEpsilonTransition[10][10], visited[10];

int numberOfStates, numberOfTransitions, stateOne, stateTwo;

char inputSymbol;

void closure(int i) {
  visited[i] = true;
  for (int j = 0; j < numberOfStates; j++) {
    if (hasEpsilonTransition[i][j] && !visited[j]) {
      printf(", Q%d ", j);
      closure(j);
    }
  }
}

int main() {

  printf("Number of states: ");
  scanf("%d", &numberOfStates);

  printf("Number of transitions: ");
  scanf("%d", &numberOfTransitions);

  printf("Enter transition table:\nstate symbol state\n");
  for (int i = 0; i < numberOfTransitions; i++) {
    scanf("%d %c %d", &stateOne, &inputSymbol, &stateTwo);
    
    if (inputSymbol == 'e')
      hasEpsilonTransition[stateOne][stateTwo] = true;
  }

  printf("\nEpsilon Closures:\n");
  for (int i = 0; i < numberOfStates; i++) {
    printf("\nState %d : { Q%d ", i, i);
    
    for (int j = 0; j < numberOfStates; j++)
      visited[j] = false;

    closure(i);
    
    printf("}");
  }

  printf("\n\n");

  return 0;
}
