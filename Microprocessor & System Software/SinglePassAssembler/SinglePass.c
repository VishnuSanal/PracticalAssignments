#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *inputFile, *optabFile, *intermediateSymtabFile, *symtabFile,
      *outputFile, *objectCodeFile;

  int locationCounter, startingAddress, optabLocation[10], i = 0, j = 0;

  char name[10], operand[10], label[10], opcode[10];

  char symtabSymbol[10], symbolAddress[10], byteObjectCode[10];

  inputFile = fopen("files/input.txt", "r");
  optabFile = fopen("files/optab.txt", "r");

  intermediateSymtabFile = fopen("files/intermediateSymtab.txt", "w+");
  symtabFile = fopen("files/symtab.txt", "w+");
  outputFile = fopen("files/output.txt", "w+");

  objectCodeFile = fopen("files/objectcode.txt", "w");

  fscanf(inputFile, "%s%s%s", label, opcode, operand);

  if (strcmp(opcode, "START") == 0) {
    startingAddress = atoi(operand);

    strcpy(name, label);

    locationCounter = startingAddress;
  }

  fscanf(inputFile, "%s%s%s", label, opcode, operand);

  while (strcmp(opcode, "END") != 0) {

    if (strcmp(label, "-") == 0) {

      char optabOpcode[10], optabObjectCode[10];

      fscanf(optabFile, "%s%s", optabOpcode, optabObjectCode);

      while (!feof(optabFile)) {

        if (strcmp(optabOpcode, opcode) == 0) {

          optabLocation[i++] = locationCounter + 1;

          fprintf(intermediateSymtabFile, "%s\t%s\n", operand, "*");
          fprintf(outputFile, "%s\t0000\n", optabObjectCode);

          locationCounter += 3;

          break;
        } else
          fscanf(optabFile, "%s%s", optabOpcode, optabObjectCode);
      }
    } else {

      rewind(intermediateSymtabFile);

      fscanf(intermediateSymtabFile, "%s%s", symtabSymbol, symbolAddress);

      while (!feof(intermediateSymtabFile)) {

        if (strcmp(symtabSymbol, label) == 0) {

          fprintf(symtabFile, "%s\t%d\n", label, locationCounter);

          j++;
          fprintf(outputFile, "%d\t%d\n", optabLocation[j], locationCounter);
          i++;

          break;

        } else
          fscanf(intermediateSymtabFile, "%s%s", symtabSymbol, symbolAddress);
      }

      if (strcmp(opcode, "RESW") == 0)
        locationCounter += 3 * atoi(operand);
      else if (strcmp(opcode, "BYTE") == 0) {

        int length = strlen(operand), index = 0;

        for (int k = 2; k < length; k++)
          byteObjectCode[index++] = operand[k];

        fprintf(outputFile, "%s\t%s\n", byteObjectCode, "-");

        locationCounter += length - 2;

        break;

      } else if (strcmp(opcode, "RESB") == 0)
        locationCounter += atoi(operand);
      else if (strcmp(opcode, "WORD") == 0) {
        locationCounter += 3;

        fprintf(outputFile, "%s\t%s\n", operand, "#");

        break;
      }
    }

    rewind(optabFile);

    fscanf(inputFile, "%s%s%s", label, opcode, operand);
  }

  rewind(outputFile);

  int programLength = locationCounter - startingAddress;

  char objectCodeOne[10], objectCodeTwo[10];

  fprintf(objectCodeFile, "H^%s^%d^0%x\n", name, startingAddress,
          programLength);

  fprintf(objectCodeFile, "T^00%d^0%x", startingAddress, programLength);

  fscanf(outputFile, "%s%s", objectCodeOne, objectCodeTwo);

  while (!feof(outputFile)) {

    if (strcmp(objectCodeTwo, "0000") == 0)
      fprintf(objectCodeFile, "^%s%s", objectCodeOne, objectCodeTwo);
    else if (strcmp(objectCodeTwo, "-") == 0) {

      fprintf(objectCodeFile, "^");

      for (int k = 0; k < strlen(objectCodeOne); k++)
        fprintf(objectCodeFile, "%d", objectCodeOne[k]);

    } else if (strcmp(objectCodeTwo, "#") == 0) {
      fprintf(objectCodeFile, "^");
      fprintf(objectCodeFile, "%s", objectCodeOne);
    }

    fscanf(outputFile, "%s%s", objectCodeOne, objectCodeTwo);
  }

  rewind(outputFile);

  fscanf(outputFile, "%s%s", objectCodeOne, objectCodeTwo);

  while (!feof(outputFile)) {

    if (strcmp(objectCodeTwo, "0000") != 0) {

      if (strcmp(objectCodeTwo, "-") != 0) {

        if (strcmp(objectCodeTwo, "#") != 0) {

          fprintf(objectCodeFile, "\n");

          fprintf(objectCodeFile, "T^%s^02^%s", objectCodeOne, objectCodeTwo);
        }
      }
    }

    fscanf(outputFile, "%s%s", objectCodeOne, objectCodeTwo);
  }

  fprintf(objectCodeFile, "\nE^00%d\n\n", startingAddress);

  return 0;
}