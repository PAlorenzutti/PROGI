#include<stdio.h>

int main(){

    int a, b, x, y, i, quantidade;
    scanf("%d%d", &a, &b);

    quantidade = 0;

    for(i = 0; i < 3; i++){
        scanf("%d %d", &x, &y);
        if(a * x + b == y){
            quantidade++;
        }
    }

    if(quantidade == 3){
        printf("Todos");
    }else if(quantidade == 2){
        printf("Dois");
    }else if(quantidade == 1){
        printf("Um");
    }else{
        printf("Nenhum");
    }

    return 0;

}