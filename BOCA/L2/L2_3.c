#include<stdio.h>

int testePar(int numero){

    if(numero % 2 == 0){
        return 1;
    }else{
        return 0;
    }

}


int main(){

    int quantidade, numero, maior, menor, n = 0, par = 0, impar = 0;
    float media = 0;
    scanf("%d", &quantidade);

    if(quantidade > 0){
        scanf("%d", &numero);
        maior = numero;
        menor = numero;        
    }else{
        return 0;
    }

    while(1){
        n++;
        media = media + numero;

        if(numero > maior){
            maior = numero;
        }

        if(numero < menor){
            menor = numero;
        }

        if(testePar(numero)){
            par++;
        }else{
            impar++;
        }        

        if(quantidade == 1){
            break;
        }

        scanf("%d", &numero);
        quantidade--;

    }

    printf("%d ", maior);
    printf("%d ", menor);
    printf("%d ", par);
    printf("%d ", impar);
    printf("%.6f", (float)media/n);

    return 0;

}