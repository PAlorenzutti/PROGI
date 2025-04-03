#include <stdio.h>
#include <ctype.h>

int intervalo(char caractere){
    if(caractere >= 65 && caractere <= 90 || caractere >= 48 && caractere <= 57){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char c1, c2, c3, c4;

    scanf("%c%c %c%c", &c1, &c2, &c3, &c4);

    c1 = toupper(c1);
    c2 = toupper(c2);
    c3 = toupper(c3);
    c4 = toupper(c4);

    if(intervalo(c1) && intervalo(c2) && intervalo(c3) && intervalo(c4)){
        if(c1 == c3 && c2 == c4){
            printf("IGUAIS");
        }else{
            printf("DIFERENTES");
        }
    }else{
        printf("Invalido");
    }

    return 0;
}