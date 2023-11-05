#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    float valor;
    struct No* prox;
} No;

void lista_inserir_no_ordenado(No** L, float valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (*L == NULL || valor < (*L)->valor) {
        novoNo->prox = *L;
        *L = novoNo;
    } else {
        No* atual = *L;
        while (atual->prox != NULL && atual->prox->valor < valor) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

int main() {
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* file = fopen("1kk_rand_float.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char line[20];
    clock_t start, end;
    double time_taken;

    while (fgets(line, sizeof(line), file)) {
        float valor = atof(line);

        start = clock();
        lista_inserir_no_ordenado(&lista_nao_ordenada, valor);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Inserção na lista não ordenada: %.6f segundos\n", time_taken);

        // Inserir na lista ordenada
        start = clock();
        lista_inserir_no_ordenado(&lista_ordenada, valor);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Inserção na lista ordenada: %.6f segundos\n", time_taken);
    }

    fclose(file);

    No* atual = lista_nao_ordenada;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    atual = lista_ordenada;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
