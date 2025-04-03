#include<stdio.h>

int main(){

    int termo1, termo2, aux, quantidade;

    scanf("%d", &quantidade);

    if(quantidade == 0){
        printf("\n");
        return 0;
    }

    scanf("%d %d", &termo1, &termo2);

    if(quantidade > 0){
        printf("%d ", termo1);
        quantidade--;
    }

    if(quantidade > 0){
        printf("%d ", termo2);
        quantidade--;
    }

    while(quantidade > 0){
        aux = termo1 + termo2; //soma os dois últimos termos
        termo1 = termo2; //transforma o segundo termo como o primeiro
        termo2 = aux;   //o segundo termo vira a soma
        printf("%d ", termo2);
        quantidade--;
    }

    return 0;

}