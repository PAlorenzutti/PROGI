#include<stdio.h>

int main(){

    float nota1, nota2;
    float media;

    scanf("%f%f", &nota1, &nota2);

    media = (nota1 + nota2)/2;

    if(media>=7){
        printf("%.1f - Aprovado", media);
    }else if(media<5){
        printf("%.1f - Reprovado", media);
    }else{
        printf("%.1f - De Recuperacao", media);
    }

    return 0;

}