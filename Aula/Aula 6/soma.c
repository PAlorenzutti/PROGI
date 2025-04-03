#include<stdio.h>

float soma(float x, float y){

    float result;

    result = x + y;

    return result;

}

int main(){

    float num1, num2, resultado;
    scanf("%f%f", &num1, &num2);

    resultado = soma(num1, num2);

    printf("%.2f", resultado);
    return 0;

}
