#include<stdio.h>

int main(){

    int a, b, c, d, aux, mmc, mdc;

    scanf("%d%d", &a, &b);

    c = a;
    d = b;

    if(a > b){
        aux = a;
    }else{
        aux = b;
    }

    mmc = aux;

    while(1){
        if(mmc % a == 0 && mmc % b == 0){
            break;
        }
        mmc++;
    }

    mdc = (c * d)/mmc;  

    printf("%d %d", mdc, mmc);

    return 0;

}