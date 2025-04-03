#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Questão 1

typedef struct{
    char nome[50];
    int matricula;
    float P1, P2;
    float T1, T2;
    float media;
}tInfoAluno;

//Questão 2

typedef struct{
    tInfoAluno alunos[60];
    int qtd;
}tListaAlunos;

//Questão 3

tListaAlunos leTurma(){
    FILE *fr;
    tListaAlunos turma;

    int numeroTurma;

    char nomeArquivo[15];

    printf("Digite o numero da turma: ");

    scanf("%d", &numeroTurma);

    sprintf(nomeArquivo, "turma%02d.txt", numeroTurma);

    if(!(fr = fopen(nomeArquivo, "r"))){
        printf("Erro");
        exit(1);
    }

    turma.qtd = 0;

    while(!feof(fr)){
        fgets(turma.alunos[turma.qtd].nome, 50, fr);
        fscanf(fr, "%d\n", &turma.alunos[turma.qtd].matricula);
        fscanf(fr, "%f %f %f %f\n", &turma.alunos[turma.qtd].P1, &turma.alunos[turma.qtd].T1, &turma.alunos[turma.qtd].P2, &turma.alunos[turma.qtd].T2);
        turma.qtd++;
    }

    fclose(fr);

    return turma;
}

// Questão 4

tListaAlunos calculaMediaParcial(tListaAlunos turma){
    int i;

    for(i = 0; i < turma.qtd; i++){
        turma.alunos[i].media = 0.4 * turma.alunos[i].P1 + 0.4 * turma.alunos[i].P2 + 0.1 * turma.alunos[i].T1 + 0.1 * turma.alunos[i].T2;
    }

    return turma;
}

// Questão 5

tListaAlunos ordenaTurma(tListaAlunos turma){
    int i, j;
    tInfoAluno temp;

    for(i = 0; i < turma.qtd; i++){
        for(j = 0; j < turma.qtd - 1; j++){
            if(turma.alunos[j].matricula > turma.alunos[j + 1].matricula){
                temp = turma.alunos[j + 1];
                turma.alunos[j + 1] = turma.alunos[j];
                turma.alunos[j] = temp;
            }
        }
    }

    return turma;
}

//Questão 6
/*
tListaAlunos intercalaTurmas (tListaAlunos A, tListaAlunos B){
    int i, j;
    tListaAlunos turma;

    turma.qtd = 0;

    for(j = 0; j < A.qtd; j++){
        turma.alunos[j] = A.alunos[j];
        turma.qtd++;
    }

    for(j = 0; j < B.qtd; j++){
        turma.alunos[turma.qtd] = B.alunos[j];
        turma.qtd++;
    }

    turma = ordenaTurma(turma);

    return turma;
}
*/

tListaAlunos intercalaTurmas(tListaAlunos A, tListaAlunos B){
    int i, j;
    tListaAlunos turma;

    turma.qtd = 0;

    i = 0;
    j = 0;

    while (i < A.qtd && j < B.qtd) {
        if (A.alunos[i].matricula < B.alunos[j].matricula) {
            turma.alunos[turma.qtd] = A.alunos[i];
            i++;
        } else {
            turma.alunos[turma.qtd] = B.alunos[j];
            j++;
        }

        turma.qtd++;
    }

    while(i < A.qtd){
        turma.alunos[turma.qtd] = A.alunos[i];
        i++;
        turma.qtd++;
    }


    while(j < B.qtd){
        turma.alunos[turma.qtd] = B.alunos[j];
        j++;
        turma.qtd++;
    }

    return turma;
}

// Questão 7

void escreveTurma(tListaAlunos turma){
    int i;

    FILE *fw;

    if(!(fw = fopen("turmas.txt", "w"))){
        printf("Erro");
        exit(1);
    }

    for(i = 0; i < turma.qtd; i++){
        int j = 0;

        while(turma.alunos[i].nome[j] != '\n'){
            fprintf(fw, "%c", turma.alunos[i].nome[j]);
            j++;
        }


        fprintf(fw, ", %d, %.2f, ", turma.alunos[i].matricula, turma.alunos[i].media);

        if(turma.alunos[i].media >= 7){
            fprintf(fw, "AP\n");
        }else{
            fprintf(fw, "PF\n");
        }
    }

    fclose(fw);
}

void printarTurma(tListaAlunos turma){
    int i;

    for(i = 0; i < turma.qtd; i++){
        printf("\n");
        printf("%s", turma.alunos[i].nome);
        printf("%d\n", turma.alunos[i].matricula);
        printf("%.2f %.2f ", turma.alunos[i].P1, turma.alunos[i].T1);
        printf("%.2f %.2f\n", turma.alunos[i].P2, turma.alunos[i].T2);
        printf("%.2f\n", turma.alunos[i].media);
    }
}

int main(){
    tListaAlunos A, B, turma;

    A = leTurma();

    A = calculaMediaParcial(A);

    A = ordenaTurma(A);

    B = leTurma();

    B = calculaMediaParcial(B);

    B = ordenaTurma(B);

    turma = intercalaTurmas(A, B);

    escreveTurma(turma);

    printarTurma(turma);

    return 0;
}