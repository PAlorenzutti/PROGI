#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    float soma, media;
    int numero, menor, maior, i;

    printf("Digite o n�mero: ");
    scanf("%d", &numero);

    if(numero != 0){
        maior = numero;
        menor = numero;
        i = soma = 0;
    }

    while(numero != 0){
        if(numero > maior){
            maior = numero;
        }
        if(numero < menor){
            menor = numero;
        }
        soma = soma + numero;
        i++;
        printf("\nDigite o n�mero: ");
        scanf("%d", &numero);
    }

    media = (float)(soma/i);

    printf("\nMenor: %d\n", menor);
    printf("\nMaior: %d\n", maior);
    printf("\nM�dia: %.2f\n", media);
    return 0;

}