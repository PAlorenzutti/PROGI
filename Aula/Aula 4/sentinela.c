#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    float soma, media;
    int numero, menor, maior, i;

    printf("Digite o número: ");
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
        printf("\nDigite o número: ");
        scanf("%d", &numero);
    }

    media = (float)(soma/i);

    printf("\nMenor: %d\n", menor);
    printf("\nMaior: %d\n", maior);
    printf("\nMédia: %.2f\n", media);
    return 0;

}