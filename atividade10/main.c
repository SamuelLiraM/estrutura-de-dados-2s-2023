#include <stdio.h>
#include <string.h>
#include "tabela_hash.h"

int main() {
    
    hash_table_init();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    printf("A chave 'chave2' existe na tabela? %d\n", hash_table_contains("chave2"));

    char* valor = hash_table_get("chave1");
    if (valor != NULL) {
        printf("Valor associado a chave 'chave1': %s\n", valor);
    }

    hash_table_remove("chave2");

    printf("A chave 'chave2' foi removida? %d\n", hash_table_contains("chave2"));

    hash_table_destroy();

    return 0;
}
