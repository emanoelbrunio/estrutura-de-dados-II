#include <stdio.h>
#include <stdlib.h>

int isPrime (int x, int y){

    if (y == 1){
        return 0;
    }
    else if (x % y  == 0){
        return 1;
    }
    else {
        return isPrime(x, y-1);
    }
}

int main(void) {
    int x;

    printf("\nVerificar se o numero natural e primo: ");
    scanf("%d", &x);
    
    int ver = isPrime(x, x-1);
    
    if (ver != 1){
        printf("\nPrimo: %d\n", x);
    }
    else {
        printf("\n%d nao eh primo\n", x);
    }
    return 0;
}

