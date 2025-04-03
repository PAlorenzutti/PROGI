#include<stdio.h>

int main(){

    int contador = 0;
    int n1, n2, pares;

    scanf("%d", &pares);

    while(contador < pares){
        scanf("%d%d", &n1, &n2);
        printf("%d\n", n1 + n2);
        contador++;
    }

    return 0;

}