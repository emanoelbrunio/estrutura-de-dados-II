#include <iostream>
#include <stdio.h>
#include <stdlib.h>


void invert_vet(int vet[], int len, int i);
void show_vet(int vet[], int i, int len);


int main(){
	
	int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int len = sizeof(vet)/sizeof(vet[0]);
	int i = 0;
	invert_vet(vet, len-1, i);
	show_vet(vet, i, len);
	return 0;
}

void invert_vet(int vet[], int len, int i){
	int aux;
	if(i<len){
		aux = vet[i];
		vet[i] = vet[len];
		vet[len] = aux;
		invert_vet(vet, len-1, i + 1);
	}	
}

void show_vet(int vet[], int i, int len){
	for(i = 0; i<len; i++){
		printf("%i\n", vet[i]);
	}
}
