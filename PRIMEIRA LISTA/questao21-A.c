#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mdc (int a , int b ) {
    int m = a ;

    if ( a < b ) {
        m = mdc(a , b - a );
    }
    else if ( a > b ) {
        m = mdc ( a - b , a );
    }
    return m ;
}

int main(void) {
    int a, b;

    printf("Digite dois valores: ");
    scanf("%d %d", &a, &b);
    int max = mdc(a, b);

    printf("Maximo divisor comum: %d", max);
    return 0;
}