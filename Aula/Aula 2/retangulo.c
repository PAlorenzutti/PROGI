#include<stdio.h>
#include<locale.h>
#include<math.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(pow(a,2) == pow(b,2) + pow(c,2) || pow(b,2) == pow(a,2) + pow(c,2) || pow(c,2) == pow(a,2) + pow(b,2)){
        printf("O triângulo é retângulo.");
    }else{
        printf("O triângulo não é retângulo.");
    }

    return 0;

}