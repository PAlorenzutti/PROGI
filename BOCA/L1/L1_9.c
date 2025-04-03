#include<stdio.h>

int main(){

    char minuscula, maiuscula;

    scanf("%c", &minuscula);

    if(minuscula >= 97 && minuscula <= 122){
        maiuscula = minuscula - 32;
        printf("%c(%d)", maiuscula, maiuscula);
    }else if (minuscula >= 65 && minuscula <= 90){
        printf("A letra deve ser minuscula!");
    }else{
        printf("Nao e letra!");
    }

    return 0;
}