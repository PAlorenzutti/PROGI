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

void multiplos(int primo, int maximo)
{
    int p = primo;
    
    if(primo * 2 < maximo){
        while(p < maximo){
            p++;
            if(p == maximo){
                break;
            }            
            
            if(p % primo == 0){
                printf("%d ", p);
            }
        }
        printf("\n");
    }else{
        printf("*\n");
    }
}

int main()
{
    int n, m, j, aux, i;
    scanf("%d%d", &n, &m);

    if(n > m){
        aux = m;
        m = n;
        n = aux;
    }

    for(i = n + 1; i < m; i++){
        if(primo(i)){
            printf("%d\n", i);
            multiplos(i, m);
        }
    }

    return 0;
}