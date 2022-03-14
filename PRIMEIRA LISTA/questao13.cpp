#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int verificaBissexto(int ano){
	if((ano % 400 == 0) || ( (ano % 4 == 0) && (ano % 100 != 0) )){
		return 1;
	}else{
		return 0;
	}
}

int diaSemana(int dia, int mes, int ano);

int main(int argc, char** argv) {
	int dia = 0;
	int diaS = 0;
	int mes = 0;
	int ano = 0;
	bool verifica = true;
	char c;
	
	while(verifica){
		printf("Para saber o dia da semana de uma determinada data precisarei de algumas informações\n");
		printf("Insira o mes: ");
		scanf("%d", &mes);
		
		printf("Insira o dia: ");
		scanf("%d", &dia);
		printf("Insira o ano: ");
		scanf("%d", &ano);
		if(mes > 12){
			printf("Mes invalido! Para tentar novamente insira qualquer letra e em seguida precione enter: ");
			scanf("%s", &c);
		}
		if(((mes == 2) && (dia > 28) && (verificaBissexto(ano) == 0)) || ((mes == 4 || mes == 6 || mes == 9 || mes == 11)) && dia > 30){
			printf("Dia invalido! Para tentar novamente insira qualquer letra e em seguida precione enter: ");
			scanf("%s", &c);
		}else{
			verifica = false;
		}
		system("cls");
	}
	
	diaS = diaSemana(dia, mes, ano);
	switch(diaS){
		case 1:
			printf("O dia %d do %d de %d foi um domingo.", dia, mes, ano);
			break;
		case 2:
			printf("O dia %d do %d de %d foi uma segunda-feira.", dia, mes, ano);
			break;
		case 3:
			printf("O dia %d do %d de %d foi uma terca-feira.", dia, mes, ano);
			break;
		case 4:
			printf("O dia %d do %d de %d foi uma quarta-feira.", dia, mes, ano);
			break;
		case 5:
			printf("O dia %d do %d de %d foi uma quinta-feira.", dia, mes, ano);
			break;
		case 6:
			printf("O dia %d do %d de %d foi uma sexta-feira.", dia, mes, ano);
			break;
		case 7:
			printf("O dia %d do %d de %d foi um sabado.", dia, mes, ano);
			break;
	}
	
	return 0;
}

int diaSemana(int dia, int mes, int ano){
	int k;
	int diaS;
	int a;
	int b;
	int c;
	
	/*if(mes == 1){
		mes = 13;
		ano = ano - 1;
	}
	if(mes == 2){
		mes == 14;
		ano = ano - 1;
	}*/
	a = (14 - mes)/12;
	b = ano - a;
	c = mes + (12 * a) - 2;
	//k = (dia + 2*mes + (3*(mes + 1)/5) + ano + (ano/4) - (ano/100) + (ano/400) + 2);
	k = dia + (31*c/12) + b + (b/4) - (b/100) + (b/400); 
	diaS = (k % 7) + 1;
}
