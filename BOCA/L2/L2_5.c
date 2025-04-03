#include<stdio.h>
#include<math.h>

double pi(int termo){

    double resultado;

    resultado = 6/pow(termo, 2);

    return resultado;

}

int main(){

    int n;
    double soma = 0;

    scanf("%d", &n);

    while(n > 0){
        soma = soma + pi(n);
        n--;
    }

    printf("%.6f", sqrt(soma));
    
    return 0;

}