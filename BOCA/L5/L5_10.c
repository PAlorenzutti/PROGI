#include <stdio.h>

void OrdenaCrescente(int vet[], int qtd){
    int i, j, temp;

    for(i = 0; i < qtd; i++){
        for(j = 0; j < qtd - 1; j++){
            if(vet[j] > vet[j + 1]){
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i;

    printf("{");

    for(i = 0; i < qtd - 1; i++){
        printf("%d, ", vet[i]);
    }

    if(qtd != 0){
        printf("%d", vet[qtd - 1]);
    }

    printf("}");
}

int main(){
    int qtd;

    scanf("%d", &qtd);

    int vet[qtd];
    int i;

    for(i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }

    OrdenaCrescente(vet, qtd);

    ImprimeDadosDoVetor(vet, qtd);

    return 0;
}