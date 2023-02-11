#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(char s[], char fileName[]);

int main() {

  char label[10], inputOpcode[10], operand[10], optabOpcode[10], objectCode[3];

  int locctr, start;

  FILE *inputFile, *optabFile, *symtabFile, *intermediateFile, *lengthFile;

  inputFile = fopen("input.txt", "r");
  optabFile = fopen("optab.txt", "r");

  symtabFile = fopen("symtab.txt", "w");
  intermediateFile = fopen("intermediate.txt", "w");
  
  lengthFile = fopen("length.txt", "w");

  fscanf(inputFile, "%s\t%s\t%s", label, inputOpcode, operand);

  if (strcmp(inputOpcode, "START") == 0) {

    start = atoi(operand);

    locctr = start;

    fprintf(intermediateFile, "\t%s\t%s\t%s\n", label, inputOpcode, operand);

    fscanf(inputFile, "%s\t%s\t%s", label, inputOpcode, operand);

  } else
    locctr = 0;

  while (strcmp(inputOpcode, "END") != 0) {

    fprintf(intermediateFile, "%d\t%s\t%s\t%s\n", locctr, label, inputOpcode,
            operand);

    if (strcmp(label, "**") != 0)
      fprintf(symtabFile, "%s\t%d\n", label, locctr);

    fscanf(optabFile, "%s\t%s", optabOpcode, objectCode);

    while (strcmp(optabOpcode, "END") != 0) {

      if (strcmp(inputOpcode, optabOpcode) == 0) {

        locctr += 3;
        break;
      }

      fscanf(optabFile, "%s\t%s", optabOpcode, objectCode);
    }

    if (strcmp(inputOpcode, "WORD") == 0)
      locctr += 3;
    else if (strcmp(inputOpcode, "RESW") == 0)
      locctr += (3 * (atoi(operand)));
    else if (strcmp(inputOpcode, "BYTE") == 0)
      locctr++;
    else if (strcmp(inputOpcode, "RESB") == 0)
      locctr += atoi(operand);

    fscanf(inputFile, "%s\t%s\t%s", label, inputOpcode, operand);
  }

  fprintf(intermediateFile, "%d\t%s\t%s\t%s\n", locctr, label, inputOpcode,
          operand);

  fclose(intermediateFile);
  fclose(symtabFile);
  fclose(optabFile);
  fclose(inputFile);

  printFile("Input SIC Program:", "input.txt");
  printFile("Input Optable:", "optab.txt");

  printFile("Symbol Table:", "symtab.txt");
  printFile("Intermediate File:", "intermediate.txt");

  int length = locctr - start;

  fprintf(lengthFile, "%d", length);

  fclose(lengthFile);

  printf("\n\nLength: %d\n", length);

  return 0;
}

void printFile(char s[], char fileName[]) {

  printf("\n\n%s\n\n", s);

  FILE *file = fopen(fileName, "r");

  char string = fgetc(file);

  while (string != EOF) {

    printf("%c", string);
    string = fgetc(file);
  }

  fclose(file);
}