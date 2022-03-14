#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float* gerador(size_t n){
    srand(time(NULL));
    float* res = malloc(n * sizeof(int));
    for(size_t i = 0; i < n; i++){
        res[i] = rand() % 1000;
    }
    return res;
}

float media_iterativa(size_t n, float* res){
    float m = 0;
    for(size_t i = 0; i < n; i++){
        m += res[i];
    }
    return m / n;
}

float media_recursiva(size_t n, float* res){
    if(n == 1){
        return res[n-1];
    }
    return (res[n-1]+(n-1)*media_recursiva(n - 1, res))/n;
}

int main(){
    int v[] = {500,1000,1500,2000};
    float* res;
    for(int i = 0; i < 4; i++){
        res = gerador(v[i]);
        printf("-----------------------------\n");
        printf("media iterativa = %.2f\n",media_iterativa(v[i], res));
        printf("media recursiva = %.2f\n",media_recursiva(v[i], res));
    }
    return 0;
}
