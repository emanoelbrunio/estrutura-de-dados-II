#include <stdio.h>

int inverter(int n) {
    int x = 0;
    while (n > 0) {   
        x = 10 * x + n % 10;  
        n = n / 10;    
    }
    return x;
}

int main(void){
    
    int n;
    printf("\n");
    printf("INFORME UM NUMERO: ");
    scanf("%d", &n);

    printf("\n");
    int inv = inverter(n);

    printf("Numero invertido: %d", inv);

}

