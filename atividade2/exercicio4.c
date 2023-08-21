#include <stdio.h>
#include <locale.h>

int contar_ocorrencias(int array[], int n, int busca) {

    int contador = 0; 

    for (int i = 0; i < n; i++) {

        if (array[i] == busca) { 
            contador++; 
        }

    }

    return contador; 

}

int main() {
    
    setlocale(LC_ALL, "Portuguese");

    int array[] = {5, 25, 15, 20, 25, 30, 35, 25}; 
    int n = sizeof(array)/sizeof(array[0]);
    int busca = 25; 

    printf("Ocorrências de %d no Array: %d\n", busca, contar_ocorrencias(array, n, busca));

    return 0;

}