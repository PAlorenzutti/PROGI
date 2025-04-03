#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    int t = 1;
    int i = 0;

    printf("Digite a quantidade de termos da sequência, respectivamente:\n");
    scanf("%d", &n);

    printf("\nA sequência de ímpares até o %d° termo é:\n", n);

    while(i < n){
        printf("%d\n", t);
        i = i + 1;
        t = t + 2;
    }

    return 0;

}