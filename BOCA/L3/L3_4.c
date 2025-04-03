#include <stdio.h>

int ehPrimo(int numero){
    int i;
    int numeroDivisores = 0;

    for(i = 2; i <= numero; i++){
        if(numero % i == 0){
            numeroDivisores++;
        } 
    }

    if(numeroDivisores == 1){
        return 1;
    }else{
        return 0;
    }
}

void printarMultiplos(int numero, int limite){
    int i = 2;
    int multiplo;

    while(1){
        multiplo = numero * i;

        if(multiplo >= limite && i == 2){
            printf("*");
            break;
        }

        if(multiplo >= limite){
            break;
        }

        printf("%d ", multiplo);
        
        i++;
    }

    printf("\n");
}

int main(){
    int intervalo1, intervalo2;
    int i;

    scanf("%d %d", &intervalo1, &intervalo2);

    i = intervalo1 + 1;

    while(i < intervalo2){
        if(ehPrimo(i)){
            printf("%d ", i);

            printf("\n");

            printarMultiplos(i, intervalo2); 
        }

        i++;
    }

    return 0;
}