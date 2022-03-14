#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int somatorio(int num);

int main()
{
    int n;
    int soma = 0;
    
    printf("Digite um numero: ");
    scanf("%d", &n);
    soma = somatorio(n);
    printf("%d", soma);
    
    return 0;       
}

int somatorio(int num){
	
	if(num == 0){
		return 0;
	}
	return num + somatorio(num - 1);
}