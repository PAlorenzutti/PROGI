#include<stdio.h>

int main(){

    float temperatura, conversao;
    char escala;

    scanf("%f %c", &temperatura, &escala);

    if(escala == 'c' || escala == 'C'){
        conversao = (temperatura * 1.8) + 32;
        printf("%.2f (F)", conversao);
    }else if(escala == 'f' || escala == 'F'){
        conversao = (temperatura - 32)/1.8;
        printf("%.2f (C)", conversao);
    }

    return 0;

}