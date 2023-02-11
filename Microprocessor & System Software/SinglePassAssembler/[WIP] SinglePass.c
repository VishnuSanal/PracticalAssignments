#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *inputFile, *optabFile, *symtabFile, *symFile, *objectCodeFile;

  int locationCounter, startingAddress, programLength, symtabIndex[10],
      symtabPointer = 0;

  char name[10], operand[10], label[10], mnemonic[10], symbol[10],
      symbolAddress[10];

  inputFile = fopen("input.txt", "r");
  optabFile = fopen("optab.txt", "r");

  symtabFile = fopen("symtab.txt", "w+");
  symFile = fopen("output.txt", "w+");

  objectCodeFile = fopen("objectcode.txt", "w");

  fscanf(inputFile, "%s%s%s", label, mnemonic, operand);

  if (strcmp(mnemonic, "START") == 0) {
    startingAddress = atoi(operand);
    strcpy(name, label);
    locationCounter = startingAddress;
  }

  fscanf(inputFile, "%s%s%s", label, mnemonic, operand);

  while (strcmp(mnemonic, "END") != 0) {
    if (strcmp(label, "-") == 0) {

      char optabMnemonic[10], optabOperand[10];

      fscanf(optabFile, "%s%s", optabMnemonic, optabOperand);

      while (!feof(optabFile)) {

        if (strcmp(optabMnemonic, mnemonic) == 0) {
          symtabIndex[symtabPointer] = locationCounter + 1;

          fprintf(symtabFile, "%s\t%s\n", operand, "*");
          fprintf(symFile, "%s\t0000\n", optabOperand);

          locationCounter += 3;
          symtabPointer++;

          break;
        } else
          fscanf(optabFile, "%s%s", optabMnemonic, optabOperand);
      }

    } else {

      fseek(symtabFile, SEEK_SET, 0);
      fscanf(symtabFile, "%s%s", symbol, symbolAddress);

      while (!feof(symtabFile)) {

        if (strcmp(symbol, label) == 0) {

          int index = 0;
          char locationCounterString[10], symbolAddress[10];

          sprintf(locationCounterString, "%d", locationCounter);

          sprintf(symbolAddress, "%d", symtabIndex[index]);

          index++;

          fprintf(symFile, "%s\t%s\n", symbolAddress, locationCounterString);

          symtabPointer++;

          break;

        } else
          fscanf(symtabFile, "%s%s", symbol, symbolAddress);
      }

      if (strcmp(mnemonic, "RESW") == 0)
        locationCounter = locationCounter + 3 * atoi(operand);
      else if (strcmp(mnemonic, "BYTE") == 0) {

        char c[10];
        int length = strlen(operand), l = 0;

        locationCounter += length - 2;

        for (int k = 2; k < length; k++) {
          c[l] = operand[k];
          l++;
        }

        fprintf(symFile, "%s\t%s\n", c, "-");

        break;

      } else if (strcmp(mnemonic, "RESB") == 0)
        locationCounter += atoi(operand);
      else if (strcmp(mnemonic, "WORD") == 0) {

        locationCounter += 3;

        fprintf(symFile, "%s\t%s\n", operand, "#");

        break;
      }
    }

    fseek(optabFile, SEEK_SET, 0);

    fscanf(inputFile, "%s%s%s", label, mnemonic, operand);
  }

  fseek(symFile, SEEK_SET, 0);

  programLength = locationCounter - startingAddress;

  char objOne[10], objTwo[10];

  fprintf(objectCodeFile, "H^%s^%d^0%x\n", name, startingAddress,
          programLength);

  fprintf(objectCodeFile, "T^");

  fprintf(objectCodeFile, "00%d^0%x", startingAddress, programLength);

  fscanf(symFile, "%s%s", objOne, objTwo);

  while (!feof(symFile)) {
    if (strcmp(objTwo, "0000") == 0)
      fprintf(objectCodeFile, "^%s%s", objOne, objTwo);
    else if (strcmp(objTwo, "-") == 0) {

      fprintf(objectCodeFile, "^");

      for (int k = 0; k < strlen(objOne); k++)
        fprintf(objectCodeFile, "%d", objOne[k]);

    } else if (strcmp(objTwo, "#") == 0) {

      fprintf(objectCodeFile, "^");

      fprintf(objectCodeFile, "%s", objOne);
    }

    fscanf(symFile, "%s%s", objOne, objTwo);
  }

  fseek(symFile, SEEK_SET, 0);

  fscanf(symFile, "%s%s", objOne, objTwo);

  while (!feof(symFile)) {
    if (strcmp(objTwo, "0000") != 0)
      if (strcmp(objTwo, "-") != 0)
        if (strcmp(objTwo, "#") != 0)
          fprintf(objectCodeFile, "\nT^%s^02^%s", objOne, objTwo);
    fscanf(symFile, "%s%s", objOne, objTwo);
  }

  fprintf(objectCodeFile, "\nE^00%d\n\n\n", startingAddress);

  return 0;
}