#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n1, n2, n3, n4;
    printf("Digite os quatro números inteiros:\n");
    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);

    if(n2 > n1){
        n1 = n2;
    }

    if(n3 > n1){
        n1 = n3;
    }

    if(n4 > n1){
        n1 = n4;
    }

    printf("O maior número é: %d", n1);

    return 0;

}