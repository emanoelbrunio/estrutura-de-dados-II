#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int delta (int a, int b, int c){
    int d;

    d = (b*b) - (4 * a * c);
    return d;
}

int main(void) {

    int a, b, c, del;
    float r1, r2;

    printf("\n\nINSIRA A: ");
    scanf("%d", &a);

    printf("INSIRA B: ");
    scanf("%d", &b);

    printf("INSIRA C: ");
    scanf("%d", &c);

    del = delta(a, b, c);
    int div = 2 * a;

    r1 = -1 * b + sqrt(del);
    r1 = r1 / div;
    
    r2 = -1 * b - sqrt(del);
    r2 = r2 / div;

    if (del > 0){
        printf("\nDELTA: %d\n", del);
        printf("Ha duas raizes reais\n");
        printf("X1: %.1f e X2: %.1f\n\n", r1, r2);
    }
    else if (del == 0){
        printf("\nDELTA: %d\n", del);
        printf("Ha apenas uma raiz real (duas raizes iguais)\n");
        printf("X1: %.1f e X2: %.1f\n\n", r1, r2);
    }
    else if (del < 0){
        printf("\nDELTA: %d\n", del);
        printf("Nao ha raizes reais");
    }
    
    return 0;
}