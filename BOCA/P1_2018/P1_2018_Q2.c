#include <stdio.h>

int main(){
    int troco1, troco2;

    scanf("%d %d", &troco1, &troco2);

    if(troco1 % 5){
        troco1 = (troco1 / 5) + ((troco1 % 5) / 1);
    }else{
        troco1 = troco1 / 5;
    }

    if(troco2 % 5){
        troco2 = (troco2 / 5) + ((troco2 % 5) / 1);
    }else{
        troco2 = troco2 / 5;
    }    

    if(troco1 > troco2){
        printf("QTD troco 1 eh maior!");
    }else if(troco1 < troco2){
        printf("QTD troco 2 eh maior!");
    }else{
        printf("Iguais!");
    }
    
    return 0;
}