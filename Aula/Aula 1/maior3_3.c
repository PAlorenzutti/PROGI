#include<stdio.h>
#include<locale.h>

int main (){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int x1, x2, x3;

    printf("Digite os valores dos números inteiros:\n");
    scanf("%d%d%d", &x1, &x2, &x3);

    printf("O maior número é:\n");

    if(x2>x1){
        x1 = x2;
    }
    
    if(x3>x1){
        x1 = x3;
    }

    printf("%d", x1);

    return 0;

}