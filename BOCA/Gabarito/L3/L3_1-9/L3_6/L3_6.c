#include <stdio.h>

int EhPalindromo(int num);

int main(){
    int a;
    while(scanf("%d", &a) == 1){
        if (EhPalindromo(a) == 1) printf("S\n");
        else printf("N\n");
    }

    return 0;
}

int EhPalindromo(int num) {
    int i = 1, a = 0, b = 1, j, old = num, temp = 0;
    if (num < 10) return 1;

    for (i = 1; num > 0; i++) num /= 10; // n de casas
    for (; i > 0; i--) {
        temp = old;
        for (j = 1; j < i; j++) temp /= 10;
        a += (temp%10) * (b);
        b *= 10;
    }

    return (a/10 == old) ? 1 : 0;
}