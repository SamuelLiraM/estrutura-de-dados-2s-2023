#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

typedef struct HashNode {
    char* chave;
    char* dado;
    struct HashNode* proximo;
} HashNode;

HashNode* tabela[TABLE_SIZE];

int hash(char* chave) {
    int hash = 0;
    while (*chave) {
        hash = (hash + *chave) % TABLE_SIZE;
        chave++;
    }
    return hash;
}

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    HashNode* current = tabela[index];

    while (current != NULL) {
        if (strcmp(current->chave, chave) == 0) {
            return current->dado;
        }
        current = current->proximo;
    }

    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));

    if (new_node == NULL) {
        perror("Erro ao alocar memória para o novo nó");
        exit(1);
    }

    new_node->chave = strdup(chave);
    new_node->dado = strdup(dado);
    new_node->proximo = tabela[index];
    tabela[index] = new_node;
}

int hash_table_contains(char* chave) {
    return hash_table_get(chave) != NULL;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    HashNode* current = tabela[index];
    HashNode* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->chave, chave) == 0) {
            if (previous == NULL) {
                tabela[index] = current->proximo;
            } else {
                previous->proximo = current->proximo;
            }
            free(current->chave);
            free(current->dado);
            free(current);
            return;
        }
        previous = current;
        current = current->proximo;
    }
}

void hash_table_destroy() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = tabela[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->proximo;
            free(temp->chave);
            free(temp->dado);
            free(temp);
        }
        tabela[i] = NULL;
    }
}
