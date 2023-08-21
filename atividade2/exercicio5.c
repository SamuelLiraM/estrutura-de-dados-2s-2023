#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *produto_array(int array1[], int array2[], int n) {

    int *resultado = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) { 

        resultado[i] = array1[i] * array2[i]; 

    }

    return resultado; 
}

int main() {

    int array1[] = {5, 10, 15, 20}; 
    int array2[] = {25, 30, 35, 40}; 
    int n = sizeof(array1)/sizeof(array1[0]); 
    int *resultado = produto_array(array1, array2, n);

    printf("Resultado da Multiplicação:"); 
    
    for (int i = 0; i < n; i++) {

        printf("%d", resultado[i]); 

        if (i < n - 1) { 

            printf(", "); 

        }

    }

    printf("]\n"); 
    free(resultado);

    return 0;
    
}