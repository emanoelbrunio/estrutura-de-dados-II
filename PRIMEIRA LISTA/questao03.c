#include <stdio.h>

int main(void) {
    int i, j, resul, soma = 0;

    for (i = 0; i <= 100; i++){

        if (i % 7 == 0){
            printf("%d\n", i);
            soma = soma + i;
        }
    }
    printf("\nSOMA: %d\n\n", soma);
    return 0;
}