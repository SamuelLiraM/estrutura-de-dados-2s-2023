#include <stdio.h>
#include <stdlib.h>

int isPrimo(int n) {

if(n<2){
    return 0;
}
    
if(n % 2 == 0){
    return n == 2;
}
for (int i = 3; i*i <= n; i+=2){
    if(n % i ==0){
        return 0;
    }
}
return 1;
}

int main(int argc, char *argv[]){
    int numero =atoi(argv[1]);
    int resultado = isPrimo(numero);
    printf("%d\n", resultado);

    return 0;
}