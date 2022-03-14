#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

float hipotenusa(float catA, float catO);

int main()
{
	float catA;
	float catO;
	float h;
	
	printf("Insira o valor do cateto oposto: ");
	scanf("%f", &catO);
	printf("Insira o cateto adjacente: ");
	scanf("%f", &catA);
	
	h = hipotenusa(catA, catO);
	
	printf("A hipotenusa do triangulo eh: %.2f", h);
    
    return 0;       
}

float hipotenusa(float catA, float catO){
	
	float h = sqrtf(pow(catA, 2) + pow(catO, 2));
	return h;
	
}