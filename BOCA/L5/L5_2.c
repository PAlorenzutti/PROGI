#include <stdio.h>

typedef int tipoInfo;

typedef struct{
    tipoInfo nota[1000];
    int quantidadeNotas;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    scanf("%d", &info);
    return info;
}

int compararInfo(tipoInfo info1, tipoInfo info2){
    if(info1 < info2){
        return -1;
    }

    if(info1 > info2){
        return 1;
    }

    return 0;
}

int menorInfo(tipoLista l, int i){
    int menor;

    menor = i;

    for(i = i + 1; i < l.quantidadeNotas; i++){
        if(compararInfo(l.nota[i], l.nota[menor]) < 0){
            menor = i;
        }
    }

    return menor;
}

int maiorInfo(tipoLista l, int i){
    int maior;

    maior = i;

        for(i = i + 1; i < l.quantidadeNotas; i++){
        if(compararInfo(l.nota[i], l.nota[maior]) > 0){
            maior = i;
        }
    }

    return maior;
}

tipoLista mudarPosicao(tipoLista l, int i, int j){
    tipoInfo temp;

    temp = l.nota[i];
    l.nota[i] = l.nota[j];
    l.nota[j] = temp;

    return l;
}

tipoLista ordenarCrescenteSimples(tipoLista l){
    int i, j;

    for(i = 0; i < l.quantidadeNotas - 1; i++){
        j = menorInfo(l, i);
        l = mudarPosicao(l, i, j);
    }

    return l;
}

tipoLista ordenarDecrescenteSimples(tipoLista l){
    int i, j;

    for(i = 0; i < l.quantidadeNotas - 1; i++){
        j = maiorInfo(l, i);
        l = mudarPosicao(l, i, j);
    }

    return l;
}

int compararCrescente(tipoLista l){
    int i;
    tipoLista copia = l;

    copia = ordenarCrescenteSimples(copia);

    for(i = 0; i < l.quantidadeNotas; i++){
        if(l.nota[i] != copia.nota[i]){
            return 0;
        }
    }

    return 1;
}

int compararDecrescente(tipoLista l){
    int i;
    tipoLista copia = l;

    copia = ordenarDecrescenteSimples(copia);

    for(i = 0; i < l.quantidadeNotas; i++){
        if(l.nota[i] != copia.nota[i]){
            return 0;
        }
    }

    return 1;
}

int compararIgual(tipoLista l){
    int i;

    for(i = 0; i < l.quantidadeNotas - 1; i++){
        if(l.nota[i] != l.nota[i + 1]){
            return 0;
        }
    }

    return 1;
}

int main(){
    tipoLista l;

    scanf("%d", &l.quantidadeNotas);

    int i;

    for(i = 0; i < l.quantidadeNotas; i++){
        l.nota[i] = lerInfo();
    }

    if(l.quantidadeNotas == 1 || compararIgual(l)){
        printf("CRESCENTE&DECRESCENTE");
    }else if(compararCrescente(l)){
        printf("CRESCENTE");
    }else if(compararDecrescente(l)){
        printf("DECRESCENTE");
    }else{
        printf("DESORDENADO");
    }

    return 0;
}