#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcao(int m, int n) {
    if(m == 0){
        return n + 1;
    }
    else if(m > 0 && n == 0) {
        return (funcao(m-1, 1));
    }

    else if(m > 0 && n > 0) {
        return funcao(m-1, (funcao(m, n-1)));
    }
}

int main() {

    int m, n, i, j, in;

	printf("informe m e n: ");
    scanf("%d %d", &m, &n);

	for (i = 0; i <= m; i++){

		for (j = 0; j <= n; j++){

			in = funcao(m, n);	
		}
	}
	printf("RETORNO: %d", in);

	return 0;
}