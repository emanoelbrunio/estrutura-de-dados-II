#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    float pi=0, x=1;
    
	for (i = 1; i <= 1000; i++) {

        if (i % 2 != 0 ){
        	pi = pi + 4 / x;
		}
		else {
        	pi = pi - 4 / x;
		}
        x = x + 2;
		printf("\n");
		printf("PI: %.10f", pi);
    }
	
	return 0;
}
