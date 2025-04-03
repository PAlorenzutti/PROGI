#include<stdio.h>

int main(){

    int numero, maior, i = 0;
    float media = 0;
    scanf("%d", &numero);

    maior = numero;
    
    while(numero != 0){
        i++;
        media = media + numero;
        if(numero > maior){
            maior = numero;
        }
        printf("%d %.6f\n", maior, (float)media/i);
        scanf("\n%d", &numero);
    }

    return 0;

}