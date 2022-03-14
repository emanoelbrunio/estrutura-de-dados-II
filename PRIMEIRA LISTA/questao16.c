#include <stdio.h>


int main(){

char a;
int lado1, lado2;

printf("Lado 1: \n");
scanf("%d", &lado1);
printf("Lado 2: \n");
scanf("%d", &lado2);

printf("Digite um caractere: \n");
scanf(" %c", &a);

printf("\n");
for(int i = 1; i <= lado1; i++){
    for(int j = 1; j <= lado2; j++){
        printf("%c", a);
    }
    printf("\n");
}
return 0;
}
