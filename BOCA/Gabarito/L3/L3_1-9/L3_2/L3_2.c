#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main(){
    float num1, num2;
    char c;
    scanf("%f", &num1);

    while (scanf("%f %c", &num2, &c) == 2) { num1 = (c == '+') ? Soma(num1, num2) : (c == '-') ? Subtracao(num1, num2) : (c == '/') ? Divisao(num1, num2) : Multiplicacao(num1, num2); }
    printf("%.2f", num1);

    return 0;
}

float Soma(float num1, float num2){ return num1 + num2; }
float Subtracao(float num1, float num2){ return num1 - num2; }
float Divisao(float num1, float num2){ return num1 / num2; }
float Multiplicacao(float num1, float num2){ return num1 * num2; }