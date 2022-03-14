#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fatorial (int x ) {
    if ( x == 0) {
        return 1;
    }
    else {
        return x * fatorial ( x - 1);
    }
}

int main(void) {
    int x;

    printf("\nCalcular fatorial de: ");
    scanf("%d", &x);
    int resul = fatorial(x);

    printf("\nFatorial de %d e %d", x, resul);

    return 0;
}