#include<stdio.h>
#include<math.h>

int main(){

    float x1, y1, x2, y2;
    float altura;
    float largura;

    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

    altura = fabs(y1 - y2);

    largura = fabs(x1 - x2);

    printf("%.2f", 2 * (altura + largura));

    return 0;

}