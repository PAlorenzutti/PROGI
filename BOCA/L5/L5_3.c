#include <stdio.h>
#include <math.h>

typedef int tipoInfo;

typedef struct{
    tipoInfo *altura;
    int quantidadePostes;
    tipoInfo maiorAltura;
    tipoInfo diferenca;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    scanf("%d", &info);
    return info;
}


tipoLista maiorDiferenca(tipoLista l){
    int i;

    l.diferenca = fabs(l.altura[0] - l.altura[1]);
    l.maiorAltura = l.diferenca;

    for(i = 1; i < l.quantidadePostes - 1; i++){
        l.diferenca = fabs(l.altura[i] - l.altura[i + 1]);

        if(l.diferenca > l.maiorAltura){
            l.maiorAltura = l.diferenca;
        }
    }

    return l;
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

void pesquisaSimples(tipoLista l){
    int i;

    for(i = 0; i < l.quantidadePostes - 1; i++){
        l.diferenca = fabs(l.altura[i] - l.altura[i + 1]);

        if(!compararInfo(l.diferenca, l.maiorAltura)){
            printf(" (%d %d)", i, i + 1);
        }
    }
}

int main(){
    tipoLista l;

    scanf("%d", &l.quantidadePostes);

    tipoInfo alturas[l.quantidadePostes];

    int i;

    for(i = 0; i < l.quantidadePostes; i++){
        alturas[i] = lerInfo();
    }

    l.altura = alturas;

    if(l.quantidadePostes <= 1){
        printf("IMPOSSIVEL");
    }else{
        l = maiorDiferenca(l);
        pesquisaSimples(l);
    }


    return 0;
}