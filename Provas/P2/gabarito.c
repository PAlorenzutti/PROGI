#include <stdio.h>
#include <stdlib.h>

// questao 1

typedef struct {
    int dia;
    int hora;
    int duracao;
} tInfoEvento;

// questao 2

typedef struct {
    tInfoEvento info [168];
    int n;
} tListaEventos;

// questao 5

typedef struct {
    int mat [24] [7];
} tMatrizEventos;

// questao 3

int comparaEventos (tInfoEvento e1, tInfoEvento e2){
    if (e1.dia < e2.dia){
        return -1;
    }
    if (e1.dia > e2.dia){
        return +1;
    }
    if (e1.hora < e2.hora){
        return -1;
    }
    if (e1.hora > e2.hora){
        return +1;
    }
    return 0;
}

// questao 4

tListaEventos incluiEvento (tListaEventos agenda, tInfoEvento e){
    int i, 
        j;
    for (i = 0; i < agenda.n; i++){
        if (comparaEventos (e, agenda.info[i])<0){
            for (j = agenda.n; j > i; j--) {
                agenda.info[j] = agenda.info[j-1];
            }
            agenda.info[i] = e;
            agenda.n++;
            return agenda;
        }
    }
    agenda.info[agenda.n] = e;
    agenda.n++;
    return agenda;
}

// questao 6

tMatrizEventos controlaAgenda (tListaEventos agenda){
    tMatrizEventos ctAg;
    int i, j;
    for (i = 0; i < 24; i++){
        for (j = 0; j < 7; j++){
            ctAg.mat[i][j] = 0;
        }
    }
    for (i = 0; i < agenda.n; i++) {
        for (j = 0; j < agenda.info[i].duracao; j++){
            ctAg.mat[agenda.info[i].dia] [agenda.info[i].hora + j] = 1;
        }
    }
    return ctAg;
}


// questao 7

tListaEventos leAgenda (void){
    tListaEventos ag;
    tInfoEvento e;
    int len;
    FILE* fp;
    if (!(fp = fopen ("agenda.txt", "r"))){
        printf("Erro abertura agenda.txt\n");
        exit(1);
    }
    ag.n = 0;
    while (!feof(fp)){
        fscanf (fp, "%d %d %d\n", &e.dia, &e.hora, &e.duracao);
        ag = incluiEvento (ag, e);
    }
    fclose(fp);
    return ag;
}

// questao 8

int inclusaoPossivel (tInfoEvento e, tMatrizEventos ctAg){
    int j;
    for (j = 0; j < e.duracao; j++){
        if (ctAg.mat[e.dia][e.hora+j]){
            return 0;
        }
    }
    return 1;
}

tMatrizEventos atualizaControleAgenda (tInfoEvento e, tMatrizEventos ctAg){
    int j;
    for (j = 0; j < e.duracao; j++){
        ctAg.mat[e.dia][e.hora+j] = 1;

    }
    return ctAg;
}

tListaEventos atualizaAgenda (tListaEventos ag){
    tInfoEvento e;
    tMatrizEventos ctAg;
    ctAg = controlaAgenda (ag);
    FILE* fp;
    if (!(fp = fopen ("atualizacao.txt", "r"))){
        printf("Erro abertura atualizacao.txt\n");
        exit(1);
    }
    while (!feof(fp)){
        fscanf (fp, "%d %d %d", &e.dia, &e.hora, &e.duracao);
        if (inclusaoPossivel(e, ctAg)){
            ag = incluiEvento(ag, e);
            ctAg = atualizaControleAgenda(e, ctAg);
        }
    }
    fclose(fp);
    return ag;
}

// questao 9

void escreveAgenda (tListaEventos ag) {
    int i;
    FILE* fp;
    if (!(fp = fopen ("atualizada.txt", "w"))){
        printf("Erro abertura atualizada.txt\n");
        exit(1);
    }
    for (i = 0; i < ag.n; i++) {
        fprintf (fp, "%d %d %d\n", ag.info[i].dia, ag.info[i].hora, ag.info[i].duracao);
    }
    fclose (fp);
}

// questao 10

int main(){
    tListaEventos agenda;
    agenda = leAgenda();
    agenda = atualizaAgenda(agenda);
    escreveAgenda(agenda);
    return 0;
}