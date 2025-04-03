#include <stdio.h>

typedef int tipoInfo;

typedef struct{
    tipoInfo numero[100];
    int quantidade;
    tipoInfo alvo;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    scanf("%d", &info);
    return info;
}

tipoLista lerLista(){
    tipoLista l;

    scanf("%d", &l.alvo);

    scanf("%d", &l.quantidade);

    int i;

    for(i = 0; i < l.quantidade; i++){
        l.numero[i] = lerInfo();
    }

    return l;
}

int pesquisa(tipoLista l){
    int i;

    for(i = 0; i < l.quantidade; i++){
        if(l.numero[i] == l.alvo){
            return i;
        }
    }

    return l.quantidade;
}

int main(){
    tipoLista l;

    l = lerLista();

    printf("RESP:%d", pesquisa(l));

    return 0;
}