#include <stdio.h>

int main(){
	
	int linha, coluna, i, j;
	int soma, total = 0, atual;

	scanf("%d %d", &linha, &coluna);

	for(i = 0; i < linha; i++){
		soma = 0;
		for(j = 0; j < coluna; j++){
			scanf("%d", &atual);
			soma += atual;
		}
		total += soma;
		printf("%d\n", soma);
	}

	printf("%d", total);

	return 0;
}
