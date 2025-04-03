#include <stdio.h>

int EhPar(int x);
void PrintaPares(int N);
void PrintaImpares(int N);

int main()
{
    int type, interval;
    scanf("%d %d", &type, &interval);

    if (type == 0) PrintaPares(interval);
    else PrintaImpares(interval);

    return 0;
}

int EhPar(int x){
    return (x%2 == 0);
}

void PrintaPares(int N){
    int i = 0, j = 2;
    for (; i < N; i++, j+=2) printf("%d ", j);
}

void PrintaImpares(int N){
    int i = 0, j = 1;
    for (; i < N; i++, j+=2) printf("%d ", j);
}

