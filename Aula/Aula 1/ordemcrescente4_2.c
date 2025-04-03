#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int x1, x2, x3, x4, maior;
    printf("\nDigite os quatro números inteiros:\n");
    scanf("%d%d%d%d", &x1, &x2, &x3, &x4);

    if (x1 > x2){
        maior = x1;
        x1 = x2;
        x2 = maior;
    }

    if (x2 > x3) {
        maior = x2;
        x2 = x3;
        x3 = maior;
    }

    if (x3 > x4){
        maior = x3;
        x3 = x4;
        x4 = maior;
    }

    if (x1 > x2){
        maior = x1;
        x1 = x2;
        x2 = maior;
    }

    if (x2 > x3){
        maior = x2;
        x2 = x3;
        x3 = maior;
    }

    if (x1 > x2){
        maior = x1;
        x1 = x2;
        x2 = maior;
    }

    printf("\nA ordem crescente dos números inseridos é: %d < %d < %d < %d\n\n", x1, x2, x3, x4);
    
    return 0;
}