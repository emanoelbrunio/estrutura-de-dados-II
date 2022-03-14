#include<stdio.h>

int main(){

int x;
float soma = 0;
float aux;

printf("Quantos numeros voce deseja somar?\n");
scanf("%d", &x);


int i;
for(i = 1; i <= x; i++){
    printf("Digite o %d numero:\n", i);
    scanf("%f", &aux);

    soma = soma+aux;
}

printf("A soma dos numeros e %.2f\n:", soma);
return 0;
}
