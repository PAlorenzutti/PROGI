#include<stdio.h>
#include<locale.h>

int fat(int n){
    int resultado;

    if(n < 2){
        return 1;
    }

    return (n * fat(n - 1));

}

int main(){

    setlocale(LC_ALL, "portuguese_brazil");

    int numero, fatorial;
    printf("Digite o número do qual se deseja obter o fatorial: ");
    scanf("%d", &numero);

    fatorial = fat(numero);

    printf("O fatorial é: %d", fatorial);
    return 0;

}