#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define M 101

typedef struct {
    int matricula;
} Aluno;

typedef struct no {
    Aluno aluno;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

Lista *tabela[M];

Aluno criarPessoa() {
    Aluno a;
    printf("Digite a matricula: ");
    scanf("%d", &a.matricula);
    return a;
}

void imprimirPessoa(Aluno a) {
    printf("Matricula: %d\n", a.matricula);
}

Lista* criarLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

void inserirInicio(Aluno a, Lista *lista) {
    No *no = malloc(sizeof(No));
    no->aluno = a;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

No* buscarNo(int mat, No *inicio) {
    while(inicio != NULL) {
        if(inicio->aluno.matricula == mat)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL;
}

void inicializar(){
    int i;
    for(i = 0; i < M; i++)
        tabela[i] = criarLista();
}

int divisao(int mat){
    return mat % M;
}

void inserTabela(){
    Aluno al = criarPessoa();
    int pos = divisao(al.matricula);
    inserirInicio(al, tabela[pos]);
}

Aluno* buscaralunoTabela(int mat){
    int pos = divisao(mat);
    No *no = buscarNo(mat, tabela[pos]->inicio);
    if(no){
        return &no->aluno;
    }
    else {
        return NULL;
    }
}

No* remover(int mat, No *inicio) {

    while(inicio != NULL) {
        if(inicio->aluno.matricula == mat){
            inicio->aluno.matricula = NULL;
            return inicio;
        }
        else {
            inicio = inicio->proximo;
        }
    }
    return NULL;
}

int menu(){
    int resposta;

    printf("|==============================|\n");
    printf("|      ESCOLHA UMA OPCAO       |\n");
    printf("|==============================|\n");
    printf("| 1 - Inserir uma matricula    |\n");
    printf("| 2 - Buscar uma matricula     |\n");
    printf("| 3 - Remover uma matricula    |\n");
    printf("| 4 - Sair                     |\n");
    printf("|==============================|\n\n");

    printf("|==============================|\n");
    printf("| RESPOSTA: ");
    scanf("%d", &resposta);
    printf("|==============================|\n\n");

    //congelando a tela por 1000mls
    Sleep(1000);

    //limpando a tela
    system("cls");
    return resposta;
}

int main() {
    int op, mat;
    Aluno *a;
    int pos;
    No *no;

    inicializar();

    do {
        op = menu();


        if (op == 1){
            inserTabela();
            printf("\n|=============================|\n");
            printf("|   INSERIDAS COM SUCESSO!    |\n");
            printf("|=============================|\n\n");
        }
        else if (op == 2){
            printf("|============================|\n");
            printf("| BUSCAR MATRICULA: ");
            scanf("%d", &mat);
            printf("|============================|\n\n");

            a = buscaralunoTabela(mat);
            if(a) {

                printf("|===================================|\n");
                printf("|   MATRICULA ENCONTRADA: %d        |\n", a->matricula);
                printf("|===================================|\n\n");
            }
            else {
                printf("|=======================================|\n");
                printf("|  NADA ENCONTRADO, TENTE OUTRO NUMERO  |\n");
                printf("|=======================================|\n\n");
            }
        }

        else if(op == 3){
            printf("|============================|\n");
            printf("| REMOVER MATRICULA: ");
            scanf("%d", &mat);
            printf("|============================|\n\n");

            pos = divisao(mat);
            no = buscarNo(mat, tabela[pos]->inicio);            
            a = remover(mat, no);

            if(a) {

                printf("|===================================|\n");
                printf("| MATRICULA %d EXCLUIDA COM SUCESSO |\n", mat);
                printf("|===================================|\n\n");
            }
            else {
                printf("|==============================================|\n");
                printf("|  NÃO FOI ENCONTRADA A MATRICULA PARA EXCLUIR |\n");
                printf("|      TENTE NOVAMENTE COM OUTRA MATRICULA     |\n");
                printf("|==============================================|\n\n");
            }

        }

        else if (op != 1 && op != 2 && op != 3 && op != 4){
            printf("Opcao invalida, tente novamente ;) \n\n");
        }
    } while(op != 4);

    printf("|==========================================|\n");
    printf("| Eh uma pena voce sair, mas volte logo :) |\n");
    printf("|==========================================|\n\n");

    return 0;
}