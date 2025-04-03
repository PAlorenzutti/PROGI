#include<stdio.h>

int main(){

    int i, numero = -1, maior = -1, menor = 99999;
    int impar = 0;
    int soma = 0;
    int contador = 0;

    for(i = 0; numero != 0; i++){
        scanf("%d", &numero);

        if(numero == 0){
            break;
        }

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


    if(maior % 7 == 0){
        printf("%d ", maior);
    }

    if(menor % 2 == 0){
        printf("%d ", menor);
    }
    
    if(contador != 0){
        printf("%.2f ", (float)impar/contador);
    }

    if(soma == 0 && i == 0){
        printf("");
    }else{
        printf("%.2f", (float)soma/i);    
    }

    return 0;

}