#include <stdio.h>
#include <string.h>
#include <locale.h>

int busca_string(char *array[], int n, char *busca) {

    for (int i = 0; i < n; i++) {

        if (strcmp(array[i], busca) == 0) {
            return 1;
        }

    }

    return 0;

}

int main() {

    setlocale(LC_ALL, "Portuguese");

    char *array[] = {"Amor", "Bem", "Rosas"};
    int n = sizeof(array)/sizeof(array[0]);
    char *busca = "Bem";

    printf("Busca: %d\n", busca_string(array, n, busca));

    return 0;

}