#include <stdio.h>

int main(){
    int numero, somaPositivos = 0, somaNegativos = 0, qtdPositivos = 0, qtdNegativos = 0;

	do{
		scanf("%d ", &numero);

		if(numero < 0 && numero > -100){
			somaNegativos += numero;
			qtdNegativos++;
		}
        
        if(numero > 0 && numero < 100){
			somaPositivos += numero;
			qtdPositivos++;
		}

		if (numero == 101){
			break;
		}

		numero = 101;
	}while(1);   

    printf("%d %d %d %d", qtdNegativos, qtdPositivos, somaNegativos, somaPositivos);
    
    return 0;
}