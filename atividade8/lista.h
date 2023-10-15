#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    char valor;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;
} Lista;

void inicializar(Lista *lista);
int lista_verificar_existencia(No *L, char valor_busca);
int lista_verificar_ocorrencias(No *L, char valor_busca);
void lista_imprimir_inversa(No *L);
void lista_inserir_no_i(Lista *lista, int i, char valor);
void lista_remover_no_i(Lista *lista, int i);
void lista_remover_no(Lista *lista, char valor);
void imprimir(Lista *lista);
void destruir(Lista *lista);

#endif
