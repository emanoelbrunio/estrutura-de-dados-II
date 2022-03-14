#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcao(int n){
    if (n > 1){
        return n * funcao(n-1);
    }
    else {
        return 1;
    }
}

long int binomial(int n, int k){
    return funcao(n) / ( funcao(k) * funcao(n-k) );
}

int main(void){

    int n, k, x, valor;

    printf("\nQUANTAS LINHAS VOCE QUER? ");
    scanf("%d", &x);

    for (n = 0; n < x; n++){
        for (k = 0; k <= n; k++){

            valor = binomial(n, k);
            printf(" %d ", valor);

        }
        printf("\n");
    }
    return 0;
}