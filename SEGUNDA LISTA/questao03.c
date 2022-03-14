#include <stdio.h>
#include <string.h>

int funPalidramo(char *n, int tam, int posicao);
int palindromo(char *n);

int main() {

    int i = 0, posicao;
    char palavra[100];

    printf("Digite uma frase: ");
    scanf ("%[^\n]", palavra);
    
    int tama = strlen(palavra);

    for (i = 0, posicao = 0; i < tama; i++, posicao++){
        if (palavra[posicao] == ' '){
            posicao++;
        }
        palavra[i] = palavra[posicao];
    }
    
    printf("String sem espacos em branco: %s\n\n", palavra);

    palindromo(palavra);

    return 0;
}

int funPalidramo(char *n, int tam, int posicao){

    if (posicao < tam / 2){
        if (n[posicao] == n[tam - posicao - 1]){
            return funPalidramo(n, tam, posicao+1);
        }
        else{
            return 0;
        }
    }
    else{
        return 1;
    }
}
int palindromo(char *n) { 

    int aux1, x = 0;

    aux1 = funPalidramo(n, strlen(n), x);

    if (aux1 == 1) {
        printf("E um palindromo\n\n");
    }
    else {
        printf("Nao e palindromo\n\n");
    }
}