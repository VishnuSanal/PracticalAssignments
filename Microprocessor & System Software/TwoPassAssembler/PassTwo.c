#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(char s[], char fileName[]);

int main() {

  char label[10], opcode[10], operand[10], symbol[10];

  int start, address, previousAddress;

  char mnemonic[15][15] = {"LDA", "STA", "LDCH", "STCH"};

  char code[15][15] = {"33", "44", "53", "57"};

  FILE *symtabFile, *intermediateFile, *outputFile, *objectCodeFile;

  symtabFile = fopen("symtab.txt", "r");
  intermediateFile = fopen("intermediate.txt", "r");

  outputFile = fopen("output.txt", "w");
  objectCodeFile = fopen("objectcode.txt", "w");

  fscanf(intermediateFile, "%s\t%s\t%s", label, opcode, operand);

  while (strcmp(opcode, "END") != 0) {
    previousAddress = address;
    fscanf(intermediateFile, "%d%s%s%s", &address, label, opcode, operand);
  }

  int finalAddress = address;

  fclose(intermediateFile);

  intermediateFile = fopen("intermediate.txt", "r");

  fscanf(intermediateFile, "\t%s\t%s\t%s", label, opcode, operand);

  if (strcmp(opcode, "START") == 0) {

    fprintf(outputFile, "\t%s\t%s\t%s\n", label, opcode, operand);
    fprintf(objectCodeFile, "H^%s^00%s^00%d\n", label, operand, finalAddress);

    fscanf(intermediateFile, "%d%s%s%s", &address, label, opcode, operand);

    start = address;

    fprintf(objectCodeFile, "T^00%d^%d", address, previousAddress - start);
  }

  while (strcmp(opcode, "END") != 0) {

    if (strcmp(opcode, "BYTE") == 0) {

      fprintf(outputFile, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);

      fprintf(objectCodeFile, "^");

      for (int i = 2; i < (strlen(operand) - 1); i++) {

        char operandObjectCode[10];

        sprintf(operandObjectCode, "%X", operand[i]);

        fprintf(outputFile, "%s", operandObjectCode);
        fprintf(objectCodeFile, "%s", operandObjectCode);
      }

      fprintf(outputFile, "\n");
    } else if (strcmp(opcode, "WORD") == 0) {

      char operandObjectCode[10];

      sprintf(operandObjectCode, "%d", atoi(operand));

      fprintf(outputFile, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode,
              operand, operandObjectCode);
      fprintf(objectCodeFile, "^00000%s", operandObjectCode);
    } else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0))
      fprintf(outputFile, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);

    else {

      int index = 0;

      while (strcmp(opcode, mnemonic[index]) != 0)
        index++;

      if (strcmp(operand, "COPY") == 0)
        fprintf(outputFile, "%d\t%s\t%s\t%s\t%s0000\n", address, label, opcode,
                operand, code[index]);

      else {

        int add;

        rewind(symtabFile);

        fscanf(symtabFile, "%s%d", symbol, &add);

        while (strcmp(operand, symbol) != 0)
          fscanf(symtabFile, "%s%d", symbol, &add);

        fprintf(outputFile, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode,
                operand, code[index], add);

        fprintf(objectCodeFile, "^%s%d", code[index], add);
      }
    }

    fscanf(intermediateFile, "%d%s%s%s", &address, label, opcode, operand);
  }

  fprintf(outputFile, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
  fprintf(objectCodeFile, "\nE^00%d", start);

  fclose(objectCodeFile);
  fclose(intermediateFile);
  fclose(symtabFile);
  fclose(outputFile);

  printFile("Intermediate File:", "intermediate.txt");
  printFile("Symbol Table:", "symtab.txt");
  printFile("Output File:", "output.txt");
  printFile("Object Code:", "objectcode.txt");

  printf("\n\n");

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