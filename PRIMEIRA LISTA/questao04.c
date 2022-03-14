#include <stdio.h>
int main(void) {
    int i, j, resul, soma = 0;

    for (i = 2; i <= 100; i++){
        resul = 0;
        for (j = 2; j < i; j++){
            if (i % j == 0) { 
                resul++;
            }
        }
        if (resul == 0){
            printf("%d\n", i);
            soma = soma + i;
        } 
    }
    printf("\nSOMA: %d\n\n", soma);
    return 0;
}
