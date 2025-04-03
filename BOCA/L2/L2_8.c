#include <stdio.h>

int primo(int numero)
{
    int i, divisor = 0;

    if(numero < 2){
        return 0;
    }

    for(i = 1; i <= numero; i++){
        if(numero % i == 0){
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
    int n, m, aux, i;
    scanf("%d%d", &n, &m);

    if(n > m){
        aux = m;
        m = n;
        n = aux;
    }

    printf("RESP:");

    for(i = n + 1; i < m; i++){
        if(primo(i)){
            printf("%d ", i);
        }
    }

    return 0;
}