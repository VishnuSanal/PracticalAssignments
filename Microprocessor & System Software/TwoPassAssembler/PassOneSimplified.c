#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *inputFile, *optabFile, *intermediateFile, *symtabFile, *lengthFile;

  char label[10], inputOpcode[10], operand[10];

  int locationCounter = 0, startingAddress = 0;

  inputFile = fopen("files/input.txt", "r");
  optabFile = fopen("files/optab.txt", "r");

  intermediateFile = fopen("files/intermediate.txt", "w");
  symtabFile = fopen("files/symtab.txt", "w");

  lengthFile = fopen("files/length.txt", "r");

  fscanf(inputFile, "%s\t%s\t%s\n", label, inputOpcode, operand);

  if (strcmp(inputOpcode, "START") == 0) {

    startingAddress = atoi(operand);

    locationCounter = startingAddress;

    fprintf(intermediateFile, "\t\t%s\t%s\t%s\n", label, inputOpcode, operand);

    fscanf(inputFile, "%s\t%s\t%s\n", label, inputOpcode, operand);

  } else
    locationCounter = 0;

  while (strcmp(inputOpcode, "END") != 0) {

    fprintf(intermediateFile, "%d\t%s\t%s\t%s\n", locationCounter, label,
            inputOpcode, operand);

    if (strcmp(label, "**") != 0)
      fprintf(symtabFile, "%s\t%d\n", label, locationCounter);

    char optabOpcode[10], optabObjectCode[10];

    fscanf(optabFile, "%s\t%s\n", optabOpcode, optabObjectCode);

    while (strcmp(optabOpcode, "END")) {

      if (strcmp(inputOpcode, optabOpcode) == 0) {

        locationCounter += 3;
        break;
      }

      fscanf(optabFile, "%s\t%s\n", optabOpcode, optabObjectCode);
    }

    if (strcmp(inputOpcode, "WORD") == 0)
      locationCounter += 3;
    else if (strcmp(inputOpcode, "BYTE") == 0)
      locationCounter += 1;
    else if (strcmp(inputOpcode, "RESW") == 0)
      locationCounter += 3 * atoi(operand);
    else if (strcmp(inputOpcode, "RESB") == 0)
      locationCounter += atoi(operand);

    fscanf(inputFile, "%s\t%s\t%s\n", label, inputOpcode, operand);
  }

  fprintf(intermediateFile, "%d\t%s\t%s\t%s\n", locationCounter, label,
          inputOpcode, operand);

  int length = startingAddress - locationCounter;

  fprintf(lengthFile, "%d", length);

  fclose(inputFile);
  fclose(optabFile);

  fclose(intermediateFile);
  fclose(symtabFile);

  fclose(lengthFile);

  printf("Output files generated\n");

  return 0;
}
