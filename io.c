#include "selforg.h"

FILE* openFile(char* fileName, char* mode) {
    FILE* file = fopen(fileName, mode);
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        exit(1);
    }
    return file;
}

void closeFile(FILE* file) {
    fclose(file);
}