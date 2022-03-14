#include <stdio.h>
#include <stdlib.h>

int divisao(int chave, int TABLE_SIZE){
    // esse & serve para evitar numeros negativos, pois ele
    // vai desconsiderar o bit de sinal negativo
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int multiplicacao(int chave, int TABLE_SIZE){

    float A = 0.71703181;
    float valor = chave * A;
    valor = valor - (int) valor;
    return (int) (TABLE_SIZE * valor);
}

int dobra(int chave, int TABLE_SIZE){

  int num_bits = 5;

  int parte1 = chave >> num_bits;
  int parte2 = chave & (TABLE_SIZE-1);

  return (parte1 ^ parte2);
}

int inserir(){
    int valor;

    printf("INSIRA UM VALOR: ");
    scanf("%d", &valor);
    return valor;
}

int main(){

    int TABLE_SIZE = 100;
    int vet[10];
    int i;
    int chave;
    int resul;

    printf("|====================|\n");
    printf("| INSIRA 10 VALORES  |\n");
    printf("|====================|\n");

    for (i = 0; i < 10; i++){
        vet[i] = inserir();
        
    }

    printf("DOBRA: \n");
    for (i = 0; i < 10; i++){
        chave = vet[i];
        resul = dobra(chave, TABLE_SIZE);
        
        printf("i: %d\t", i+1);
        if (resul > TABLE_SIZE){
            printf("ERRO: VALOR: %d > LOCAL: %d;", vet[i], resul);
            printf("\n");
        }
        else {
            printf("valor: %d > Local: %d;", vet[i], resul);
            printf("\n");
        }
    }
    printf("\n");

    printf("MULTIPLICACAO: \n");
    for (i = 0; i < 10; i++){
        chave = vet[i];
        resul = multiplicacao(chave, TABLE_SIZE);

        printf("i: %d\t", i+1);
        if (resul > TABLE_SIZE){
            printf("ERRO: VALOR: %d > LOCAL: %d;", vet[i], resul);
            printf("\n");
        }
        else {
            printf("valor: %d > Local: %d;", vet[i], resul);
            printf("\n");
        }
    }
    printf("\n");

    printf("DIVISAO: \n");
    for (i = 0; i < 10; i++){
        chave = vet[i];
        resul = divisao(chave, TABLE_SIZE);

        printf("i: %d\t", i+1);
        if (resul > TABLE_SIZE){
            printf("ERRO: VALOR: %d > LOCAL: %d;", vet[i], resul);
            printf("\n");
        }
        else {
            printf("valor: %d > Local: %d;", vet[i], resul);
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}