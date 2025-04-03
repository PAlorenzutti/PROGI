//Aluno: Pedro Alexandre Simões Lorenzutti
//Máquina: 14

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int hora;
    int duracao;
}tInfoEvento;

typedef struct{
    tInfoEvento eventos[168];
    int qtd;
}tListaEventos;

typedef struct{
    int matriz[24][7];
}tMatrizEventos;

int comparaEventos(tInfoEvento e1, tInfoEvento e2){
    if(e1.dia < e2.dia){
        return -1;
    }else if(e1.dia > e2.dia){
        return 1;
    }else{
        if(e1.hora < e2.hora){
            return -1;
        }
        else if(e1.hora > e2.hora){
            return 1;
        }else{ 
            if(e1.duracao < e2.duracao){
                return -1;
            }else if(e1.duracao > e2.duracao){
                return 1;
            }else {
                return 0;
            }
        }
    }
}

//Algoritmo bubblesort

tListaEventos ordernarAgenda(tListaEventos agenda){
    int i, j;
    tInfoEvento temp;

    for(i = 0; i < agenda.qtd; i++){
        for(j = 0; j < agenda.qtd - 1; j++){
            if(comparaEventos(agenda.eventos[j], agenda.eventos[j + 1]) > 0){
                temp = agenda.eventos[j];
                agenda.eventos[j] = agenda.eventos[j + 1];
                agenda.eventos[j + 1] = temp;
            }
        }
    }

    return agenda;
}

//Algoritmo quicksort.

/*
tListaEventos incluiEvento(tListaEventos agenda, tInfoEvento e){
    int i, j;

    for(i = 0; i < agenda.qtd; i++){
        if(comparaEventos(e, agenda.eventos[i]) < 0){
            for(j = agenda.qtd; j > i; j--){
                agenda.eventos[j] = agenda.eventos[j - 1];
            }

            agenda.eventos[j] = e;
            agenda.qtd++;
            
            return agenda;
        }
    }

    agenda.eventos[agenda.qtd] = e;
    agenda.qtd++;
    
    return agenda;
}
*/


tListaEventos incluiEvento(tListaEventos agenda, tInfoEvento e){
    agenda.eventos[agenda.qtd] = e;
    agenda.qtd++;

    agenda = ordernarAgenda(agenda);

    return agenda;  
}


tMatrizEventos criarAgendaVazia(){
    int i, j;
    tMatrizEventos controle;

    for(i = 0; i < 24; i++){
        for(j = 0; j < 7; j++){
            controle.matriz[i][j] = 0;
        }
    }

    return controle;
}

tMatrizEventos controlaAgenda(tListaEventos agenda){
    int i, j;
    tMatrizEventos controle;

    controle = criarAgendaVazia();

    for(i = 0; i < agenda.qtd; i++){
        for(j = agenda.eventos[i].hora; j < agenda.eventos[i].hora + agenda.eventos[i].duracao; j++){
            controle.matriz[j][agenda.eventos[i].dia] = 1;
        }
    }

    return controle;
}

tListaEventos leAgenda(){
    tListaEventos agenda;
    tInfoEvento e;
    FILE *fr;

    if( !(fr = fopen("agenda.txt", "r")) ){
        printf("Erro.");
        exit(1);
    }

    agenda.qtd = 0;

    while(!feof(fr)){
        fscanf(fr, "%d %d %d\n", &e.dia, &e.hora, &e.duracao);
        agenda = incluiEvento(agenda, e);
    }

    fclose(fr);

    return agenda;
}

int inclusaoPossivel(tInfoEvento e, tMatrizEventos controle){
    int j;

    for(j = e.hora; j < e.hora + e.duracao; j++){
        if(controle.matriz[j][e.dia] == 1){
            return 0;
        }
    }

    return 1;
}

tListaEventos atualizaAgenda(tListaEventos agenda){
    tMatrizEventos controle;
    tInfoEvento e;

    controle = controlaAgenda(agenda);

    FILE *fr;

    if( !(fr = fopen("atualizacao.txt", "r")) ){
        printf("Erro.");
        exit(1);
    }

    while(!feof(fr)){
        fscanf(fr, "%d %d %d\n", &e.dia, &e.hora, &e.duracao);
        if(inclusaoPossivel(e, controle)){
            agenda = incluiEvento(agenda, e);
            controle = controlaAgenda(agenda);
        }
    }

    fclose(fr);

    return agenda;
}

void escreveAgenda(tListaEventos agenda){
    FILE *fw;

    if(!(fw = fopen("atualizada.txt", "w"))){
        printf("Erro");
        exit(1);
    }

    int i;

    for(i = 0; i < agenda.qtd; i++){
        fprintf(fw, "%d %d %d\n", agenda.eventos[i].dia, agenda.eventos[i].hora, agenda.eventos[i].duracao);
    }

    fclose(fw);
}

void printarAgenda(tListaEventos agenda){
    int i;

    for(i = 0; i < agenda.qtd; i++){
        printf("%d %d %d\n", agenda.eventos[i].dia, agenda.eventos[i].hora, agenda.eventos[i].duracao);
    }
}

void printarControle(tMatrizEventos controle){
    printf("%10s%10s%11s%13s%12s%10s%12s\n", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday");

    int i, j;

    for(i = 0; i < 24; i++){
        printf("%d", i);

        for(j = 0; j < 7; j++){
            if(j == 0 || j == 1 || j == 5){
                printf("%10d", controle.matriz[i][j]);
            }
            
            if(j == 2){
                printf("%11d", controle.matriz[i][j]);
            }

            if(j == 3){
                printf("%13d", controle.matriz[i][j]);
            }

            if(j == 4 || j == 6){
                printf("%12d", controle.matriz[i][j]);
            }
        }

        printf("\n");
    }
}

int main(){
    tListaEventos agenda;
    tMatrizEventos controle;
    tInfoEvento e;

    agenda = leAgenda();

    agenda = atualizaAgenda(agenda);

    escreveAgenda(agenda);

    return 0;
}