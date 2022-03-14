#include <stdio.h>


int conversao(int x){
    int f;
    f = 9*x/5 + 32;
    return f;
}

int main(){

for(int i = 30; i <= 50; i++){
    printf("Temperatura em Celsius: %d Temperatura em Fahrenheit %d\n", i, conversao(i));
}
return 0;
}
