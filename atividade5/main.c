#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_WORDS 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return 2;
    }

    char *words[MAX_WORDS];
    int wordCount = 0;

    char buffer[100];  

    while (wordCount < MAX_WORDS && fscanf(inputFile, "%s", buffer) != EOF) {
        words[wordCount] = strdup(buffer);
        wordCount++;
    }

    fclose(inputFile);

    bubbleSort(words, wordCount);

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar arquivo de saída");
        return 3;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(outputFile);

    return 0;
}
