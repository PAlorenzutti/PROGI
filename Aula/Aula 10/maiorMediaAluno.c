#include <stdio.h>
#include <locale.h>
#define MAX 100

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int aluno[MAX];
    float media[MAX];
    float mediaTurma, soma;
    int n, indice;

    soma = 0;
    n = 0;

    printf("\nDigite a matr�cula do %d� aluno: ", n + 1);
    scanf("%d", &aluno[n]);

    while(aluno[n] > -1 && n < MAX){
        printf("\nDigite a m�dia do %d� aluno: ", n + 1);
        scanf("%f", &media[n]);
        soma += media[n];
        n++;

        printf("\nDigite a matr�cula do %d� aluno: ", n + 1);
        scanf("%d", &aluno[n]);
    }

    if(n){
        mediaTurma = soma/n;
    }else{
        printf("Sequ�ncia vazia\n.");
        return 0;
    }

    indice = 0;

    while(indice < n){
        if(media[indice] > mediaTurma){
            printf("\nO aluno de matr�cula %d est� acima da m�dia da turma %.2f com m�dia %.2f", aluno[indice], mediaTurma, media[indice]);
        }

        indice++;
    }

    return 0;
}