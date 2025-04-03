#include<stdio.h>

int main(){

    int n, m, aux;
    scanf("%d%d", &n, &m);

    if(n > m){
        aux = n;
        n = m;
        m = aux;
    }

    printf("RESP:");

    while(m > n){
        n++;

        if(n == m){
            break;
        }

        if(n % 2 == 0){
            printf("%d ", n);
        }
    }

    return 0;

}