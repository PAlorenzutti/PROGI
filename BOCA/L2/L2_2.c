#include<stdio.h>

int testeTres(int numero){

    if(numero % 3 == 0){
        return 1;
    }else{
        return 0;
    }

}

int testeQuatro(int numero){

    if(numero % 4 == 0){
        return 1;
    }else{
        return 0;
    }

}

int testeSete(int numero){

    if(numero % 7 == 0){
        return 1;
    }else{
        return 0;
    }

}


int main(){

    int inicio, fim;
    scanf("%d%d", &inicio, &fim);

    while(inicio < fim){
        inicio++;

        if(inicio == fim){
            break;
        }

        if(testeTres(inicio) || testeQuatro(inicio) || testeSete(inicio)){
            printf("%d ", inicio);
        }

    }

    return 0;

}