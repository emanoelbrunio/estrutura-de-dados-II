#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fib (int x ){
    if(x < 2){
        return x ;
    }
    else {
        return fib (x - 1) + fib (x - 2);
    }
}

int main(void) {
    int x;

    printf("\nQual elemento da serie de Fibonacci voce quer: ");
    scanf("%d", &x);
    
    int f = fib(x);

    printf("\nFibonacci: %d\n", f);

    return 0;
}

