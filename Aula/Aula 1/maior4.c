#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n1, n2, n3, n4;
    printf("Digite os quatro n�meros inteiros:\n");
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

    printf("O maior n�mero �: %d", n1);

    return 0;

}