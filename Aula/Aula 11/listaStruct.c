#include <stdio.h>
#define MAX 100

typedef struct{
    int info[MAX];
    int n;
}tipoLista;

tipoLista leitura(){
    tipoLista l;

    l.n = 0;

    scanf("%d", &l.info[l.n]);

    while(l.info[l.n] > 0){
        l.n++;
        scanf("%d", &l.info[l.n]);
    }

    return l;
}

void apresenta(tipoLista l){
    int i;

    for(i = 0; i < l.n; i++){
        printf("%d ", l.info[i]);
    }
}

int main(){
    tipoLista lint;

    lint = leitura();

    apresenta(lint);

    return 0;
}
