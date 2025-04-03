#include <stdio.h>

typedef int tipoInfo;

typedef struct{
    tipoInfo numero[100];
    tipoInfo qtd;
    tipoInfo intervalo1;
    tipoInfo intervalo2;
    tipoInfo dentro;
    tipoInfo fora;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    scanf("%d", &info);
    return info;
}

tipoLista lerLista(tipoLista l){
    int i; 

    for(i = 0; i < l.qtd; i++){
        l.numero[i] = lerInfo();
    }

    scanf("%d %d", &l.intervalo1, &l.intervalo2);

    return l;
}

tipoLista verificarIntervalo(tipoLista l){
    int i;

    l.dentro = 0;
    l.fora = 0;

    for(i = 0; i < l.qtd; i++){
        if(l.numero[i] >= l.intervalo1 && l.numero[i] <= l.intervalo2){
            l.dentro++;
        }else{
            l.fora++;
        }
    }

    return l;
}

int main(){
    tipoLista l;

    scanf("%d", &l.qtd);

    l = lerLista(l);

    l = verificarIntervalo(l);

    printf("%d %d", l.dentro, l.fora);

    return 0;
}