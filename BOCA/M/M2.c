#include<stdio.h>

int main(){

    float real;

    scanf("%f", &real);

    printf("INTEIRO:%d,REAL:%.2f", (int)real, real - (int)real);

    return 0;
}