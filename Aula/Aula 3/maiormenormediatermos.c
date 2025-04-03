#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, i, t, menor, maior, soma;
    i = 0;
    menor = 99999;
    maior = -1;
    soma = 0;

    printf("Digite o número de termos a serem digitados:\n");
    scanf("%d", &n);
    printf("\n");

    if(n > 0){
        while(i < n){
            printf("Digite o termo: ");
            scanf("%d", &t);

            if(t < menor){
                menor = t;
            }
            
            if(t > maior){
                maior = t;
            }

            i = i + 1;
            soma = soma + t;
        }
    }else{
        printf("Sequência vazia.\n");
    }

    printf("\nO menor termo da sequência digitada é: %d\n", menor);
    printf("\nO maior termo da sequência digitada é: %d\n", maior);
    printf("\nA media entre os números da sequência é: %.2f\n\n", (float)soma/n);

    return 0;

}