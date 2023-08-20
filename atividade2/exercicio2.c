#include<stdlib.h>
#include<stdio.h>

void maiorMenor(int *numero, int tam, int *menor, int *maior){
    int i;
    *menor = *numero;
    *maior = *numero;
    for(i = 1; i < tam; i++){
        if(*menor > *(numero + i))
            *menor = *(numero + i);
        if(*maior < *(numero + i))
            *maior = *(numero + i);
    }
}

int main(){
    int menor, maior, n[10] = {5,7,9,6,4,8,9,1,2,3};

    maiorMenor(n, 10, &menor, &maior);
    printf("Menor: %d\tMaior: %d\n", menor, maior);
}