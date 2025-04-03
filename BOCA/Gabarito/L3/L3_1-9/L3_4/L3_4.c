#include <stdio.h>

int EhPrimo(int num);
void ImprimeMultiplos(int num, int max);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    a++;
    while(a < b){
        if (EhPrimo(a) > 0) {
            printf("%d\n", a);
            ImprimeMultiplos(a, b);
        }
        a++;
    }

    return 0;
}

int EhPrimo(int num){ 
    int i;
    for (i = 2; i < num; i++){ if (num % i == 0) return 0; }
    return num;
}

void ImprimeMultiplos(int num, int max){
    int i = 2;
    if (num * i >= max) printf("*");
    else for (; num * i < max; i++) printf("%d ", num * i);
    printf("\n");
}