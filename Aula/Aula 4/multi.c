#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n1, n2, i = 0, produto = 0;
    printf("Digite os dois fatores da multiplica��o:\n");
    scanf("%d %d", &n1, &n2);

    while(i < n2){
        produto = produto + n1;
        i++;
    }

    printf("O resultado da multiplica��o �: %d", produto);
    return 0;

}