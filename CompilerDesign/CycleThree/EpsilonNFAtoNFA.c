#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char inputDFA[20][3], finalState[30];

int numberOfTransitions;

int contains(char c, char str[]) {
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == c)
            return true;
    return false;
}

void add(char str[], char c) {
    if (!contains(c, str))
    {
        int len = strlen(str);
        str[len] = c;
        str[len + 1] = '\0';
    }
}

void addState(char currentState, char nextState) {
    for (int i = 0; i < numberOfTransitions; i++)
        if (inputDFA[i][0] == nextState && inputDFA[i][1] != 'e')
            printf("%c %c %c\n", currentState, inputDFA[i][1], inputDFA[i][2]);
        else if (inputDFA[i][0] == nextState && inputDFA[i][1] == 'e' && inputDFA[i][2] != currentState)
            addState(currentState, inputDFA[i][2]);
}

int main() {
    printf("Enter the number of transitions: ");
    scanf("%d", &numberOfTransitions);

    printf("Enter transition table:\nstate symbol state\n");
    for (int i = 0; i < numberOfTransitions; i++)
        scanf(" %c %c %c", &inputDFA[i][0], &inputDFA[i][1], &inputDFA[i][2]);

    printf("Final states: ");
    scanf("%s", finalState);

    printf("Result NFA transition table:\n");
    for (int i = 0; i < numberOfTransitions; i++)
        if (inputDFA[i][1] != 'e')
            printf("%c %c %c\n", inputDFA[i][0], inputDFA[i][1], inputDFA[i][2]);
        else
            addState(inputDFA[i][0], inputDFA[i][2]);

    for (int i = numberOfTransitions - 1; i >= 0; i--)
        if (contains(inputDFA[i][2], finalState) && inputDFA[i][1] == 'e')
            add(finalState, inputDFA[i][0]);

    printf("Final states : {%s}\n\n", finalState);
}
