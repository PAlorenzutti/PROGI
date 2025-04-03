#include <stdio.h>

int somaDigitos(int numero){

	int resto, soma = 0;

	while(numero != 0){
		resto = numero % 10;
		soma += resto;
		numero = (numero - resto)/10;
	}

    return soma;
}

int main(){
    int numero;

    scanf("%d", &numero);

    while(numero >= 10){
        numero = somaDigitos(numero);
    }

    printf("RESP:%d", numero);

    return 0;
}