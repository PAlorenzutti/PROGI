#include <stdio.h>
#include <locale.h>
#define MAX 100

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int vetor[MAX];
    float media, soma;
    int n, indice;

    soma = 0;
    n = 0;

    printf("\nDigite o %d� n�mero da sequ�ncia: ", n + 1);
    scanf("%d", &vetor[n]);

    while(vetor[n] > -1 && n < MAX){
        soma += vetor[n];
        n++;

        printf("\nDigite o %d� n�mero da sequ�ncia: ", n + 1);
        scanf("%d", &vetor[n]);
    }

    if(n){
        media = soma/n;
    }else{
        printf("Sequ�ncia vazia\n.");
        return 0;
    }

    indice = 0;

    while(indice < n){
        if(vetor[indice] > media){
            printf("\nO vetor[%d] = %d est� acima da m�dia %.2f", indice, vetor[indice], media);
        }

        indice++;
    }

    return 0;
}