#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int func(int m, int n);

int main()
{
	
    int m, n;
    int retorno = 0;
    printf("Insira m e n: ");
    scanf("%d %d", &m, &n);
    
	retorno = func(m, n);
	
	printf("%d", retorno);
    
    return 0;       
}

int func(int m, int n){
	
	if(n == 1){
		return m+1;
	}
	else if(m == 1){
		return n+1;
	}
	else if(m>1 && n>1){
		return func(m, n-1) + func(m-1,n);
	}
	
}