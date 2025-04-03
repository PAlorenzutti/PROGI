#include <stdio.h>

void criarVetor(int vet[], char nome[], int vet_A[], int vet_B[], int qtd_A, int qtd_B){
    int i, qtd;

    for(i = 0; i < qtd_A; i++){
        vet[i] = vet_A[i];
        nome[i] = 'A';
    }

    int j;

    for(j = 0; j < qtd_B; j++){
        vet[i + j] = vet_B[j];
        nome[i + j] = 'B';
    }
}

void ordenarVetor(int vet[], char nome[], int qtd){
    int i, j, tempNum;
    char tempChar;

    for(i = 0; i < qtd; i++){
        for(j = 0; j < qtd - 1; j++){
            if(vet[j] > vet[j + 1]){
                tempNum = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = tempNum;

                tempChar = nome[j];
                nome[j] = nome[j + 1];
                nome[j + 1] = tempChar;
            }
        }
    }
}

void printarVetor(char nome[], int qtd){
    int i;

    for(i = 0; i < qtd; i++){
        printf("%c", nome[i]);
    }
}


int main(){
    int qtd_A, qtd_B;

    scanf("%d", &qtd_A);

    int vet_A[qtd_A];
    int i;

    for(i = 0; i < qtd_A; i++){
        scanf("%d", &vet_A[i]);
    }

    scanf("%d", &qtd_B);

    int vet_B[qtd_B];

    for(i = 0; i < qtd_B; i++){
        scanf("%d", &vet_B[i]);
    }

    int qtd;
    qtd = qtd_A + qtd_B;

    int vet[qtd];
    char nome[qtd];

    criarVetor(vet, nome, vet_A, vet_B, qtd_A, qtd_B);

    ordenarVetor(vet, nome, qtd);

    printarVetor(nome, qtd);

    return 0;
}