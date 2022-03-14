#include <stdio.h>
#include <time.h>

int algoritmoDemorado(int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    soma = i + j + k + l;
                }
            }
        }
    }
    return soma;
}

int main(void){
    time_t t;
    t = time(NULL);
    algoritmoDemorado(350);
    t = time(NULL) - t;
    printf("tempo em segundos = %d\n",t);
    return 0;
}
