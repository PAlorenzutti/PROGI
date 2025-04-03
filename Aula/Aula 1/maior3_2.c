#include<stdio.h>
#include<locale.h>

int main (){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int x1, x2, x3;

    printf("Digite os valores dos n�meros inteiros:\n");
    scanf("%d%d%d", &x1, &x2, &x3);

    printf("O maior n�mero �:\n");

    if(x1>=x2 && x1>=x3){
        printf("%d", x1);
    }else if(x2>=x1 && x2>=x3){
        printf("%d", x2);
    }else{
        printf("%d", x3);
    }
    
    return 0;

}