#include <stdio.h>

int hashSimples(int numero, int chave){
    return numero % chave;
}

int somaDigitos(int numero){

	int resto, soma = 0;

	while(numero != 0){
		resto = numero % 10;
		soma += resto;
		numero = (numero - resto)/10;
	}

    return soma;

}

void decodifica(int numero){
    scanf("%d", &numero);

    while(numero != -1){
        numero = somaDigitos(numero);
        printf("%d\n", hashSimples(numero, 17));
        scanf("%d", &numero);
    }
}

void linha(int espaco, int asterisco){
	while(espaco > 0){
		printf(" ");
		espaco--;
	}

	while(asterisco > 0){
		printf("*");
		asterisco--;
	}
}

void ampulheta(){
	int linhas, asterisco, white;

    scanf("%d", &linhas);

	asterisco = linhas;
	white = 0;

	while(asterisco >= 2){
		if(asterisco == linhas){
			linha(0, asterisco);
		}else{
			linha(white, asterisco);
		}

		if(asterisco != 2){
			printf("\n");
		}

		asterisco -= 2;
		white++;
	}

	while(asterisco <= linhas){
		linha(white, asterisco);
		printf("\n");
		asterisco += 2;
		white--;
	}
}


int main(){
    decodifica(1);

    ampulheta(1);

    return 0;
}