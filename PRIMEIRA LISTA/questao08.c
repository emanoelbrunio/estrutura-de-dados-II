#include <stdio.h>
#include <stdlib.h>
/* não entendi muito como a questão estava pedindo
entao fiz da forma como entendi */
void menu (){
    printf("|=========================================|\n");
    printf("| NUMERO DO PRODUTO   |   PRECO NO VAREJO |\n");
    printf("|=========================================|\n");
    printf("|          1          |       R$ 3,00     |\n");
    printf("|-----------------------------------------|\n");
    printf("|          2          |       R$ 4,00     |\n");
    printf("|-----------------------------------------|\n");
    printf("|          3          |       R$ 2,80     |\n");
    printf("|-----------------------------------------|\n");
    printf("|          4          |       R$ 1,95     |\n");
    printf("|-----------------------------------------|\n");
    printf("|          5          |       R$ 5,00     |\n");
    printf("|=========================================|\n");
}
int main(void){
    menu();
    int num, qtd, i, resposta;
    float tot = 0;

    do {
        printf("|============================================|\n");
        printf("| Numero do produto: ");
        scanf("%d", &num);
        printf("| Quantidade vendida em um dia: ");
        scanf("%d", &qtd);
        printf("|============================================|\n\n");

        switch (num) {
            case 1:
                tot = tot + (3 * qtd);
                break;
            case 2:
                tot = tot + (4 * qtd);
                break;
            case 3:
                tot = tot + (2.8 * qtd);
                break;
            case 4:
                tot = tot + (1.95 * qtd);
                break;
            case 5:
                tot = tot + (5 * qtd);
                break;
            default:
                printf("NUMERO DO PRODUTO NAO EXISTE\n\n");
                break;
        }

        printf("|====================================|\n");
        printf("| DESEJA ADICIONAR UM NOVO PRODUTO ? |\n");
        printf("|====================================|\n");
        printf("| 1 - SIM                            |\n");
        printf("|------------------------------------|\n");
        printf("| 2 - NAO                            |\n");
        printf("|====================================|\n\n");

        printf("|====================================|\n");
        printf("| RESPOSTA: ");
        scanf("%d", &resposta);
        printf("|====================================|\n\n");

    } while(resposta == 1);
    printf("|===========================================================|\n");
    printf("| A SOMA DE TODOS OS PRODUTOS VENDIDOS NA SEMANA: RS %.2f \n", tot);
    printf("|===========================================================|\n");

}