#include <stdio.h>
#include <stdlib.h> 

void soma( int numeros[10]){
    int total = 0; 
    for (int i = 0; i < 10; i++){ 
        total += numeros[i];
    } 
    printf("O total e de %d", total); 
}

int main (){
    int numeros[10] = {5,7,9,6}; 
    soma(numeros); 
}