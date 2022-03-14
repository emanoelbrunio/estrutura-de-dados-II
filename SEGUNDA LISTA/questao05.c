#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contfib(int n, int k){
  
    if(n == k){
        return 1; 
    }
    else if (n == 1){
        return 0;
    }
    
    /*else if (k == 0){
        return 1;
    }*/
    else if (n < k){
        return 0;
    }
    if (n > k) {
        return contfib(n-1, k) + contfib(n-2, k);
    }
}

int main (void){
    int n, k, valor;

    printf("\n\nInsira dois numeros: ");
    scanf("%d %d", &n, &k);

    valor = contfib(n, k);

    printf("ContFib(%d, %d) = %d", n, k, valor);
    return 0;
}
