#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(Lista *lista) {
    lista->cabeca = NULL;
}

int lista_verificar_existencia(No *L, char valor_busca) {
    
    No *temp = L;
    while (temp != NULL) {
        if (temp->valor == valor_busca) {
            return 1; 
        }
        temp = temp->prox;
    }
    return 0;
}

int lista_verificar_ocorrencias(No *L, char valor_busca) {
    
    int contador = 0;
    No *temp = L;
    while (temp != NULL) {
        if (temp->valor == valor_busca) {
            contador++;
        }
        temp = temp->prox;
    }
    return contador;
}

void lista_imprimir_inversa(No *L) {
    
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->prox);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(Lista *lista, int i, char valor) {
    
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    if (i == 0) {
        novo->prox = lista->cabeca;
        lista->cabeca = novo;
        return;
    }
    No *temp = lista->cabeca;
    for (int j = 0; j < i - 1; j++) {
        temp = temp->prox;
        if (temp == NULL) {
            free(novo);
            return; 
        }
    }
    novo->prox = temp->prox;
    temp->prox = novo;
}

void lista_remover_no_i(Lista *lista, int i) {
    
    if (i == 0) {
        No *temp = lista->cabeca;
        if (temp != NULL) {
            lista->cabeca = temp->prox;
            free(temp);
        }
        return;
    }
    No *temp = lista->cabeca;
    for (int j = 0; j < i - 1; j++) {
        temp = temp->prox;
        if (temp == NULL) {
            return; 
        }
    }
    if (temp->prox != NULL) {
        No *remover = temp->prox;
        temp->prox = remover->prox;
        free(remover);
    }
}

void lista_remover_no(Lista *lista, char valor_busca) {
    
    No *atual = lista->cabeca;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior == NULL) {
                lista->cabeca = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            No *remover = atual;
            atual = atual->prox;
            free(remover);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

void imprimir(Lista *lista) {
    No *temp = lista->cabeca;
    while (temp != NULL) {
        printf("%c ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void destruir(Lista *lista) {
    No *temp = lista->cabeca;
    while (temp != NULL) {
        No *remover = temp;
        temp = temp->prox;
        free(remover);
    }
}
