#include<stdio.h>
#include<math.h>
#include<locale.h>

float distancia(int Xa, int Ya, int Xb, int Yb){

    float result;

    result = sqrt(pow(Xa - Xb, 2) + pow(Ya - Yb, 2));

    return result;

}

int main(){

    setlocale(LC_ALL, "portuguese_brazil");

    int x1, y1, x2, y2, x3, y3;
    float d;
    printf("\nDigite as coordenadas, x e y, respectivamente de cada dos três pontos:\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    d = distancia(x1, y1, x2, y2);
    printf("\nA distância entre o ponto A e B é: %.2f\n", d);

    d = distancia(x2, y2, x3, y3);
    printf("\nA distância entre o ponto B e C é: %.2f\n", d);

    d = distancia(x1, y1, x3, y3);
    printf("\nA distância entre o ponto A e C é: %.2f\n\n", d);

    return 0;

}