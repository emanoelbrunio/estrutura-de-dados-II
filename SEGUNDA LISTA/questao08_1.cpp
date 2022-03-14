#include <stdio.h>
#include <stdlib.h>
//sem cauda

int fat (int n) {
    if ( n == 0) {
        return 1;
    }
    else {
        return n * fat (n - 1);
    }
}

int main(void){
    int n;
    
    printf("Fatorial de: ");
    scanf("%d", &n);
    
    int fato = fat(n);
    printf("Fatorial de %d e %d", n, fato);

    return 0;
}