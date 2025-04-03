#include<stdio.h>

int main(){

    int quantidade, numero, maior = -1, menor = 99999, i;
    int impar = 0;
    int soma = 0;
    int contador = 0;
    scanf("%d", &quantidade);  

    for(i = 0; i < quantidade; i++){

        scanf("%d", &numero);

        if(numero % 7 == 0){
            if(numero > maior){
                maior = numero;
            }
        }
        if(numero % 2 == 0){
            if(numero < menor){
                menor = numero;
            }
        }else{
            impar = impar + numero;
            contador++;
        }

        soma = soma + numero;
    }

    if(quantidade > 0){

        if(maior % 7 == 0){
            printf("%d ", maior);
        }

        if(menor % 2 == 0){
            printf("%d ", menor);
        }
        
        if(contador != 0){
            printf("%.2f ", (float)impar/contador);
        }

        printf("%.2f", (float)soma/quantidade);
    }

    return 0;

}