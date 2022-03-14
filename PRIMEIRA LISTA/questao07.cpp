#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	bool teste = true;
	int num[5];
	int i = 0;
	
	
	for(i; i<5; i++){
		printf("Digite um numero inteiro: ");
		scanf("%d", &num[i]);
		if(num[i] > 30 || num[i] <= 0){
			printf("Os valores devem ser maiores que zero e menores que 30");
			return 0;
			}
	}
	
	printf("\n");
		
	for(i = 0; i<5; i++){
		for(int j = 0; j<num[i]; j++){
			printf("*");
		}
		printf("   [%d]", num[i]);
		printf("\n");
	}
    
    return 0;       
}