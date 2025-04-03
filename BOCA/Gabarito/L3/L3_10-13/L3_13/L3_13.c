#include <stdio.h>

int CalculaValorPalavra();
int EhPrimo(int n);
int ProximoPrimo(int n);

int main()
{
    char c;
    int i = 0;
    while(i = CalculaValorPalavra()){
        if (EhPrimo(i))     printf("E primo\n");
        else                printf("Nao e primo %d\n", ProximoPrimo(i));
    }

    return 0;
}

int CalculaValorPalavra(){
    int sum = 0;
    char c;
    while(scanf("%c", &c) == 1 && c != '\n') {
        if (c >= 'a' && c <= 'z') c -= ('a' - 1);
        else if (c >= 'A' && c <= 'Z') c -= ('A' - 27);
        else c = 0;
        sum += c;
    }
    return sum;
}

int EhPrimo(int n){
    int i = 2;
    for (; i < n; i++) if (n%i == 0) return 0;
    return (n != 0 && n != 1);
}

int ProximoPrimo(int n){
    for (n++; !EhPrimo(n); n++);
    return n;
}