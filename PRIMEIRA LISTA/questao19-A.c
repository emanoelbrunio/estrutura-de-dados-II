#include <stdio.h>
#include <stdlib.h>

int delta (int a, int b, int c){
    int d;

    d = (b*b) - (4 * a * c);
    return d;
}

int main(void) {

    int a, b, c, del;
    printf("\n\nINSIRA A: ");
    scanf("%d", &a);

    printf("INSIRA B: ");
    scanf("%d", &b);

    printf("INSIRA C: ");
    scanf("%d", &c);

    del = delta(a, b, c);
    if (del > 0){
        printf("\nDELTA: %d\nHa duas raizes reais", del);
    }
    else if (del == 0){
        printf("\nDELTA: %d\nHa apenas uma raiz real (duas raizes iguais)", del);
    }
    else if (del < 0){
        printf("\nDELTA: %d\nNao ha raizes reais", del);
    }
    
    return 0;
}