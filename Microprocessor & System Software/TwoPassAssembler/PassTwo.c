#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(char s[], char fileName[]);

int main() {

  char label[10], opcode[10], operand[10], symbol[10];

  int start, address, previousAddress;

  FILE *symtabFile, *intermediateFile, *optabFile, *outputFile, *objectCodeFile;

  symtabFile = fopen("files/symtab.txt", "r");
  optabFile = fopen("files/optab.txt", "r");
  intermediateFile = fopen("files/intermediate.txt", "r");

  outputFile = fopen("files/output.txt", "w");
  objectCodeFile = fopen("files/objectcode.txt", "w");

  fscanf(intermediateFile, "%s\t%s\t%s", label, opcode, operand);

  while (strcmp(opcode, "END") != 0) {
    previousAddress = address;
    fscanf(intermediateFile, "%d%s%s%s", &address, label, opcode, operand);
  }

  int finalAddress = address;

  rewind(intermediateFile);

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

        char byteObjectCode[10];

        sprintf(byteObjectCode, "%X", operand[i]);

        fprintf(outputFile, "%s", byteObjectCode);
        fprintf(objectCodeFile, "%s", byteObjectCode);
      }

      fprintf(outputFile, "\n");
    } else if (strcmp(opcode, "WORD") == 0) {

      char wordObjectCode[10];

      sprintf(wordObjectCode, "%d", atoi(operand));

      fprintf(outputFile, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode,
              operand, wordObjectCode);

      fprintf(objectCodeFile, "^00000%s", wordObjectCode);

    } else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0))
      fprintf(outputFile, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);

    else {

      char optabOpcode[10], objectCode[10];

      fscanf(optabFile, "%s\t%s", optabOpcode, objectCode);

      while (strcmp(optabOpcode, "END") != 0 &&
             strcmp(opcode, optabOpcode) != 0)
        fscanf(optabFile, "%s\t%s", optabOpcode, objectCode);

      int symbolAddress;

      rewind(symtabFile);

      fscanf(symtabFile, "%s%d", symbol, &symbolAddress);

      while (strcmp(operand, symbol) != 0)
        fscanf(symtabFile, "%s%d", symbol, &symbolAddress);

      fprintf(outputFile, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode,
              operand, objectCode, symbolAddress);

      fprintf(objectCodeFile, "^%s%d", objectCode, symbolAddress);
    }

    fscanf(intermediateFile, "%d%s%s%s", &address, label, opcode, operand);
  }

  fprintf(outputFile, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
  
  fprintf(objectCodeFile, "\nE^00%d", start);

  fclose(objectCodeFile);
  fclose(intermediateFile);
  fclose(symtabFile);
  fclose(outputFile);

  printFile("Intermediate File:", "files/intermediate.txt");
  printFile("Symbol Table:", "files/symtab.txt");
  printFile("Output File:", "files/output.txt");
  printFile("Object Code:", "files/objectcode.txt");

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
