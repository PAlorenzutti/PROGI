#include <stdio.h>

int somadosdigitos(int n);
void parImpar(int n);
void valorPrimo(int n);

int main()
{
    int num;
    scanf("%d", &num);

    do {
        num = somadosdigitos(num);
        printf("%d ", num);
        parImpar(num);
        valorPrimo(num);    
        if (num >= 10) printf("\n");
    } while(num >= 10);

    return 0;
}

int somadosdigitos(int n){
    int i = 0;
    if (n == 10) i = 1;
    else {
        while (n > 0) {
            i += n%10;
            n /= 10;
        }
    }
    return i;
}

void parImpar(int n){
    if (n%2 == 0) printf("Par ");
    else printf("Impar ");
}

void valorPrimo(int n){
    int i = 2, j = 0;
    for(; i < n; i++){
        if (n%i == 0){
            printf("Nao e primo");
            j = 1;
            break;
        }
    }
    if (n == 1 || n == 0) printf("Nao e primo");
    else if (j == 0) printf("Primo");
}
