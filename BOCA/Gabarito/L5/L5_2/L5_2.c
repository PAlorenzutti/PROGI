#include <stdio.h>
#include <math.h>

int getOrder(int notas[], int num);

int main() {
    int n;
    scanf("%d ", &n);

    int notas[n];
    int i;
    for (i = 0; i < n; scanf("%d", &notas[i]), i++);

    int order = getOrder(notas, n);
    if (order == 1) printf("DECRESCENTE");
    else if (order == -1) printf("CRESCENTE");
    else if (order == 0) printf("CRESCENTE&DECRESCENTE");
    else printf("DESORDENADO");

    return 0;
}

int getOrder(int notas[], int num){
    int i = 1, dif, last = 0;

    for (; i < num; i++) { if (notas[i-1] != notas[i]) { last = 1; break; } }
    if (!last) return 0;
    last = 0;

    for (; i < num; i++){
        if (notas[i-1] < notas[i]) dif = -1;
        else if (notas[i-1] > notas[i]) dif = 1;
        else dif = last;
        if (last != dif && last != 0 && i > 1) return 10;
        last = dif;
    }
    return dif;
}