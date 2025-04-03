#include <stdio.h>

int main(){
    int num1, num2;
    char sinal;

    scanf("%d %c %d", &num1, &sinal, &num2);

    if(sinal == '+'){
        printf("SOMA:%d", num1 + num2);
    }

    if(sinal == '-'){
        printf("SUB:%d", num1 - num2);
    }

    if(sinal == '*'){
        printf("MULT:%d", num1 * num2);
    }

    if(sinal == '/'){
        if(num1 % num2){
            printf("DIV:%d, RESTO:%d", num1 / num2, num1 % num2);
        }else{
            printf("DIV:%d", num1 / num2);
        }
    }

    return 0;
}