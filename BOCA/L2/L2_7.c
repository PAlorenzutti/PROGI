#include <stdio.h>

int primo(int n)
{
    int i, divisor = 0;

    if(n < 2){
        return 0;
    }

    for(i = 1; i <= n; i++){
        if(n % i == 0){
            divisor++;
        }
    }

    if(divisor == 2){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    int numero;
    scanf("%d", &numero);

    if(primo(numero)){
        printf("Primo");
    }else{
        printf("Nao primo");
    }

    return 0;
}