#include<stdio.h>
#include<locale.h>

int main (){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int x1, x2, x3;

    printf("Digite os valores dos números inteiros:\n");
    scanf("%d%d%d", &x1, &x2, &x3);

    printf("O maior número é:\n");

    if(x1>=x2){
        if(x1>=x3){
            printf("%d", x1);
        }else{
            printf("%d", x3);
        }
    }else{
        if(x2>=x3){
            printf("%d", x2);
        }else{
            printf("%d", x3);
        }
    }

    return 0;

}