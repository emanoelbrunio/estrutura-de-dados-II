#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void isPerfect(int num);

int main()
{
    
    int num = 0;
    
    printf("Digite um numero para saber se ele eh perfeito: ");
    scanf("%d", &num);
    if(num <= 1 || num >100){
		printf("O numero deve estar entre 1 e 100, logo %d nao eh valido\n", num);
		return 0;
	}else
	{
		isPerfect(num);	
	}
    
 
    return 0;       
}

void isPerfect(int num){
	
	int i, j, k;
    int fat[5];
	
	j = 0;
    k = 0;
    
    for(i = 1; i<num; i++){
		
		if(num%i == 0){
			j += i;
			fat[k] = i;
			k++;
			
		}
		
	}
	
	if(num == j){
		printf("O numero eh perfeito e seus fatores sao: ");
		for(i = 0; i<k; i++)
			printf("%d + ", fat[i]);
		printf(" = %d", num);
	}else
	{
		printf("Nao eh perfeito");
	}
	
}