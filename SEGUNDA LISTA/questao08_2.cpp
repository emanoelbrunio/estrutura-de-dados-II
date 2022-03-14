#include <stdio.h>
#include <stdlib.h>
//com cauda

int fatorial_aux(int num, int parcial){
    
    if (num == 1){
        return parcial;
    }
    
    else{
        return fatorial_aux((num - 1), (parcial * num));
    }
 }

int fat_c(int num){
    
return fatorial_aux(num, 1);

 }
 
 int main(){
    int n;
    
    printf("Fatorial de: ");
    scanf("%d", &n);
    
    int fato = fat_c(n);
    printf("Fatorial de %d e %d", n, fato);

    return 0;
 }