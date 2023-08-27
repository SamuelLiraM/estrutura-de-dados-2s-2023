#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

void calcularRegressaoLinear(Ponto pontos[], int numPontos) {
    int somatorioX = 0;
    float somatorioY = 0;
    float somatorioXY = 0;
    float somatorioX2 = 0;

    for (int i = 0; i < numPontos; i++) {
        somatorioX += pontos[i].x;
        somatorioY += pontos[i].y;
        somatorioXY += pontos[i].x * pontos[i].y;
        somatorioX2 += pontos[i].x * pontos[i].x;
    }

    float mediaX = (float)somatorioX / numPontos;
    float mediaY = somatorioY / numPontos;

    float coefAngular = (somatorioXY - numPontos * mediaX * mediaY) / (somatorioX2 - numPontos * mediaX * mediaX);
    float coefLinear = mediaY - coefAngular * mediaX;

    printf("Equação da regressão linear: y = %.2fx + %.2f\n", coefAngular, coefLinear);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int capacidade = 10;
    int numPontos = 0;
    Ponto *pontos = (Ponto *)malloc(capacidade * sizeof(Ponto));

    while (fscanf(arquivo, "%d,%f\n", &pontos[numPontos].x, &pontos[numPontos].y) == 2) {
        numPontos++;
        if (numPontos >= capacidade) {
            capacidade *= 2;
            pontos = (Ponto *)realloc(pontos, capacidade * sizeof(Ponto));
        }
    }

    fclose(arquivo);

    calcularRegressaoLinear(pontos, numPontos);

    free(pontos);

    return 0;
}
