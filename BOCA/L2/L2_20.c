#include <stdio.h>
#include <math.h>

float imagem(float a, float b, float c, float d, int x){
    float y;

    y = a * pow(x, 3) + b * pow(x, 2) + c * x + d;

    return y;
}

int main(){
    float a, b, c, d;
    int e, f, tamanho, numeroVale = 0, numeroPico = 0;
    int i = 0;

    scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);

    tamanho = (f - e) + 1;

    float y[tamanho];
    int x[tamanho];

    while(e <= f){
        y[i] = imagem(a, b, c, d, e);
        x[i] = e;
        i++;
        e++;
    }

    int j = 1;

    while(j <= tamanho - 2){
        if(y[j] > y[j - 1] && y[j] > y[j + 1]){
            printf("\nPico em x=%d", x[j]);
            numeroPico = 1;
        }

        if(y[j] < y[j - 1] && y[j] < y[j + 1]){
            printf("\nVale em x=%d", x[j]);
            numeroVale = 1;
        }

        j++;
    }

    if(!numeroPico){
        printf("\nNao ha pico");
    }

    if(!numeroVale){
        printf("\nNao ha vale");
    }

    return 0;
}