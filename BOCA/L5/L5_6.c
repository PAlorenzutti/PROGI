#include <stdio.h>

void lerNumeros(int numeros[], int quantidade){
    int i;

    for(i = 0; i < quantidade; i++){
        scanf("%d", &numeros[i]);
    }
}

int pesquisaSimples(int numerosA[], int quantidadeA, int numerosB[], int quantidadeB){
    int i, j;
    int igual = 0;

    for(i = 0; i < quantidadeB; i++){
        for(j = 0; j < quantidadeA; j++){
            if(numerosA[j] == numerosB[i]){
                igual++;
                break;
            }
        }
    }

    return igual;
}

int main(){
    int quantidadeA, quantidadeB, igual;

    scanf("%d", &quantidadeA);

    int numerosA[quantidadeA];

    lerNumeros(numerosA, quantidadeA);

    scanf("%d", &quantidadeB);

    int numerosB[quantidadeB];

    lerNumeros(numerosB, quantidadeB);

    igual = pesquisaSimples(numerosA, quantidadeA, numerosB, quantidadeB);

    if(igual == quantidadeA){
        printf("TODOS");
    }else if(igual > 0 && igual < quantidadeA){
        printf("PARCIAL");
    }else{
        printf("NENHUM");
    }

    return 0;
}