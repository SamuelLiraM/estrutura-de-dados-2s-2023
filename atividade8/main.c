#include <stdio.h>
#include "lista.h"

int main() {
    Lista lista;
    inicializar(&lista);

    lista_inserir_no_i(&lista, 0, 'A');
    lista_inserir_no_i(&lista, 1, 'B');
    lista_inserir_no_i(&lista, 2, 'A');
    lista_inserir_no_i(&lista, 3, 'C');
    lista_inserir_no_i(&lista, 4, 'A');

    printf("Lista original: ");
    imprimir(&lista);

    char valor_busca = 'A';
    int existe = lista_verificar_existencia(lista.cabeca, valor_busca);
    printf("Existe %c na lista? %s\n", valor_busca, existe ? "Sim" : "Não");

    int ocorrencias = lista_verificar_ocorrencias(lista.cabeca, valor_busca);
    printf("Ocorrencias de %c na lista: %d\n", valor_busca, ocorrencias);

    printf("Lista em ordem inversa: ");
    lista_imprimir_inversa(lista.cabeca);
    printf("\n");

    lista_remover_no_i(&lista, 2);
    printf("Lista apos a remocao do indice 2: ");
    imprimir(&lista);

    lista_remover_no(&lista, 'A');
    printf("Lista apos a remocao de todos os 'A': ");
    imprimir(&lista);

    destruir(&lista);
    return 0;
}
