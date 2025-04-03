#include <stdio.h>

void InverteVetor(int *vet, int qtd){
    int i, temp;

    for(i = 0; i < qtd/2; i++){
        temp = vet[i];
        vet[i] = vet[qtd - 1 - i];
        vet[qtd - 1 - i] = temp;
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i;

    printf("{");

    for(i = 0; i < qtd - 1; i++){
        printf("%d, ", vet[i]);
    }

    if (qtd != 0){
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

    InverteVetor(vet, qtd);

    ImprimeDadosDoVetor(vet, qtd);

    return 0;
}