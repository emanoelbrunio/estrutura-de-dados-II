#include <stdio.h>
#include <stdlib.h>

int funcao (int horas, int minutos, int segundos){
    int tot;
    if (horas == 0 || horas == 12){
        minutos = minutos * 60;
        tot = minutos + segundos;
    }
    else if (horas > 0 && horas < 12){
        minutos = minutos * 60;
        horas = horas * 60 * 60;

        tot = horas + minutos + segundos;
    }
    else if (horas > 12 && horas < 24){
        minutos = minutos * 60;
        horas = (horas - 12) * 60 * 60;

        tot = horas + minutos + segundos;
    }
    return tot;
}

int main(void) {
    int horas, minutos, segundos;

    printf("\n\n|=====================|\n");
    printf("| HORAS: DE 0 A 23    |\n");
    printf("| MINUTOS: DE 0 A 59  |\n");
    printf("| SEGUNDOS: DE 0 A 59 |\n");
    printf("|=====================|\n\n");

    do {
        printf("| HORAS: ");
        scanf("%d", &horas);
        if (horas > 23 || horas < 0){
            printf("\n|-----------------------------|\n");
            printf("| OBEDECA A TABELA DE VALORES |\n");
            printf("|-----------------------------|\n\n");
        }
    } while (horas > 23 || horas < 0);

    do {
        printf("| MINUTOS: ");
        scanf("%d", &minutos);
        if (minutos > 59 || minutos < 0){
            printf("\n|-----------------------------|\n");
            printf("| OBEDECA A TABELA DE VALORES |\n");
            printf("|-----------------------------|\n\n");
        }
    } while (minutos > 59 || minutos < 0);

    do {
        printf("| SEGUNDOS: ");
        scanf("%d", &segundos);
        if (segundos > 59 || segundos < 0){
            printf("\n|-----------------------------|\n");
            printf("| OBEDECA A TABELA DE VALORES |\n");
            printf("|-----------------------------|\n\n");
        }
    } while (segundos > 59 || segundos < 0);

    int f = funcao(horas, minutos, segundos);

    printf("\n\nQUANTIDADE SE SEGUNDOS DESDE A ULTIMA VEZ QUE O RELOGIO BATEU 12: %d SEGUNDOS", f);
    return 0;
}