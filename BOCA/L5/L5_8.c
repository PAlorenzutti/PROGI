#include <stdio.h>

void TrocaParImpar(int vet[], int qtd){
    int i, temp;

    for(i = 0; i < qtd - 1; i += 2){
        temp = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = temp;
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i;

    printf("{");

    for(i = 0; i < qtd - 1; i++){
        printf("%d, ", vet[i]);
    }

    if((qtd) != 0){
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

    TrocaParImpar(vet, qtd);

    ImprimeDadosDoVetor(vet, qtd);

    return 0;
}