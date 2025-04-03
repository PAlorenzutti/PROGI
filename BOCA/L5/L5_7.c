#include <stdio.h>

typedef int tipoInfo;

typedef struct{
    tipoInfo numeros[100];
    int quantidade;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    
    scanf("%d", &info);

    return info;
}

tipoLista lerLista(){
    tipoLista l;

    scanf("%d", &l.quantidade);

    int i;

    for(i = 0; i < l.quantidade; i++){
        scanf("%d", &l.numeros[i]);
    }

    return l;
}

tipoInfo calcularRazao(tipoLista l, int i){
    return l.numeros[i + 1] - l.numeros[i];
}

int verificarAritmetica(tipoLista l){
    int i;
    tipoInfo razao;

    razao = calcularRazao(l, 0);

    for(i = 1; i < l.quantidade - 1; i++){
        if(razao != calcularRazao(l, i)){
            return 0;
        }
    }

    return 1;
}

int main(){
    tipoLista l;

    l = lerLista();

    if(!(verificarAritmetica(l))|| l.quantidade == 1){
        printf("NAO");
    }else{
        printf("RESP:%d", calcularRazao(l, 0));
    }

    return 0;
}