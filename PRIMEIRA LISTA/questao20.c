#include <stdio.h>

int main(){
int x;
int soma = 0;
int resto;
int divisao;

printf("Digite um numero:\n");
scanf("%d", &x);

while(x != 0){
    resto = x%10;
    x = (x-resto)/10;
    soma = soma + resto;
}

printf("A soma dos digitos do numero que foi digitado, e: %d", soma);


return 0;
}
