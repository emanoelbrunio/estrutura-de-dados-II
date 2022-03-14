#include <stdio.h>
#include <stdlib.h>

struct aluno{
  int matricula;
};
typedef struct aluno Aluno;

struct hash{
  int qtd;
  int TABLE_SIZE;
  struct aluno **itens;
};
typedef struct hash Hash;

int divisao(int chave, int TABLE_SIZE);
Hash* criar(int TABLE_SIZE);
int inserir(Hash* ha, Aluno al);
int buscar(Hash* ha, int mat, Aluno* al);
int remover(Hash* ha, int mat);

int divisao(int chave, int TABLE_SIZE){
    // esse & serve para evitar numeros negativos, pois ele
    // vai desconsiderar o bit de sinal negativo
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

Hash* criar(int TABLE_SIZE){
    Hash *ha = (Hash*) malloc(sizeof(Hash));
    if (ha != NULL){
        int i;

        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (Aluno**) malloc (TABLE_SIZE * sizeof(Aluno*));

        if (ha->itens == NULL){
            free(ha);
            return NULL;
        }
        
        ha->qtd = 0;

        for (i = 0; i < ha->TABLE_SIZE; i++) {
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

int inserir(Hash *ha, Aluno aluno1){
   
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE){
        // se a tabela nao existir ou cheia ele nao insere nada e já retorna 0
        return 0;
    }
    // se nao, cria uma chave e insere a matricula
    int chave = aluno1.matricula;
    // cria a posicao com aquele numero de matricula
    int posicao = divisao(chave, ha->TABLE_SIZE);
    
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if(novo_aluno == NULL){
        // verifica se foi criado com sucesso o novo aluno
        return 0;
    }
    *novo_aluno = aluno1;
    ha->itens[posicao] = novo_aluno;
    ha->qtd++;
    return 1;
    
}

int buscar(Hash* ha, int mat, Aluno* aluno1){
    
    if(ha == NULL){
        // caso a tabela nao existam retorna 0
        return 0;
    }
    //caso exista, calcula a posicao do elemento que queremos encontrar
    int posicao = divisao(mat, ha->TABLE_SIZE);
    
    if (ha->itens[posicao] == NULL){
        // aqui verifica se tem conteudo no elemento intes daquela posicao
        //se nao tiver, retorna 0
        return 0;
    }
    
    //caso exista elementos, ele ignora o if anterior e entra aqui
    *aluno1 = *(ha->itens[posicao]);
    
    return 1;
}

int remover(Hash* ha, int mat){
   
    if(ha == NULL){
        //se a tabela nao existir, imprime e sai
        printf("\n\nNAO EXISTE TABELA\n\n");
        return 0;
    }

    int posicao = divisao(mat, ha->TABLE_SIZE);
    
    if (ha->itens[posicao] == NULL){
        return 0;
    }
    else {
        ha->itens[posicao] = NULL; 
        return 1;
    }
}

int menu(){
    int resposta;

    printf("|==============================|\n");
    printf("|      ESCOLHA UMA OPCAO       |\n");
    printf("|==============================|\n");
    printf("| 1 - Inserir dez matriculas   |\n");
    printf("| 2 - Buscar uma matricula     |\n");
    printf("| 3 - Remover uma matricula    |\n");
    printf("| 4 - Sair                     |\n");
    printf("|==============================|\n\n");

    printf("|==============================|\n");
    printf("| RESPOSTA: ");
    scanf("%d", &resposta);
    printf("|==============================|\n\n");

    return resposta;
}

int main(){

    int TABLE_SIZE = 101;
    int i;
    int matricula;
    Hash *ha = criar(TABLE_SIZE);
    Aluno aluno1;
    int resp_menu;
    
    do {
        resp_menu = menu();

        if (resp_menu == 1){
            printf("|==========================|\n");
            printf("|   INSIRA 10 MATRICULAS   |\n");
            printf("|==========================|\n");

            for (i = 0; i < 10; i++){
                printf("MATRICULA: ");
                scanf("%d", &aluno1.matricula);
                inserir(ha, aluno1);   
            }

            printf("\n");
            printf("|=============================|\n");
            printf("|   INSERIDAS COM SUCESSO!    |\n");
            printf("|=============================|\n\n");
        }

        else if (resp_menu == 2){
            printf("|============================|\n");
            printf("| BUSCAR MATRICULA: ");
            scanf("%d", &matricula);
            printf("|============================|\n\n");

            int resul = buscar(ha, matricula, &aluno1);
            int ver = aluno1.matricula;

            if (resul == 1){
                printf("|===================================|\n");
                printf("|   MATRICULA ENCONTRADA: %d         |\n", ver);
                printf("|===================================|\n\n");
            }
            else if (resul == 0) {
                printf("|=======================================|\n");
                printf("|  NADA ENCONTRADO, TENTE OUTRO NUMERO  |\n");
                printf("|=======================================|\n\n");
            }
        }

        else if (resp_menu == 3){
            int matricula_ex, verificar;

            printf("|==================================|\n");
            printf("| MATRICULA QUE DESEJA EXCLUIR: ");
            scanf("%d", &matricula_ex);
            printf("|==================================|\n\n");

            verificar = remover(ha, matricula_ex);
            if (verificar == 0){
                printf("\n\n HOUVE ALGUM ERRO AO EXCLUIR, A \nMATRICULA PODE NAO EXISTIR OU ERRO NO SISTEMA");
                printf("\n QUEM SABE TENTANDO NOVAMENTE\n\n");
            }
            else if (verificar == 1){
                printf("A MATRICULA DE NUMERO %d FOI EXCLUIDA COM SUCESSO!\n\n", matricula_ex);
            }
        }

    } while (resp_menu == 1 || resp_menu == 2 || resp_menu == 3);

    if (resp_menu == 4){
        printf("\n\nVOCE VAI SAIR DO NOSSO PROGRAMA :(\n\n");
    }
        
    return 0;
}
/*
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

int chave;
int resul;
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
printf("\n");*/
