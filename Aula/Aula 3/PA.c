#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int t, r, n;
    int i = 0;

    printf("\nDigite o termo inicial, a raz�o e a quantidade de termos da PA, respectivamente:\n");
    scanf("%d%d%d", &t, &r, &n);

    printf("\nA sequ�ncia at� o %d� termo �:\n", n);

    while(i < n){
        printf("%d\n", t);
        i = i + 1;
        t = t + r;
    }

    return 0;

}