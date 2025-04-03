#include <stdio.h>
#include <math.h>

int getMaior(int notas[], int num);
int getMenor(int notas[], int num);
float getMedia(int notas[], int num);
double getDesvio(int notas[], int num, float media);
int getAbaixo(int notas[], int num, float media);
int getAprovados(int notas[], int num);

int main() {
    int n;
    scanf("%d ", &n);

    int notas[n];
    int i;
    for (i = 0; i < n; scanf("%d", &notas[i]), i++);

    float media = getMedia(notas, n);

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d",
     getMenor(notas, n), getMaior(notas, n), media, getDesvio(notas, n, media), n - getAbaixo(notas, n, media), n - getAprovados(notas, n));

    return 0;
}

int getMaior(int notas[], int num){
    int max = -1, i = 0;
    for (; i < num; i++) if (notas[i] > max) max = notas[i];
    return max;
}

int getMenor(int notas[], int num){
    int min = 101, i = 0;
    for (; i < num; i++) if (notas[i] < min) min = notas[i];
    return min;
}

float getMedia(int notas[], int num){
    int i = 0;
    float media = 0;
    for (; i < num; i++) media += notas[i];
    return media / num;
}

double getDesvio(int notas[], int num, float media){
    int i = 0;
    float sum = 0, dif;
    for (; i < num; i++) {
        dif = notas[i] - media;
        sum += dif*dif;
    }
    return sqrt(sum / num);
}

int getAbaixo(int notas[], int num, float media){
    int n = 0, i = 0;
    for (; i < num; i++) if (notas[i] <= media) n++;
    return n;
}

int getAprovados(int notas[], int num){
    int n = 0, i = 0;
    for (; i < num; i++) if (notas[i] >= 70) n++;
    return n;
}