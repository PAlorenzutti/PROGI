#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int colunas;
	int numeros[7][7];
} tCartela;

void ImprimeCartela(tCartela cartela);
tCartela LeCartela();

int main(){
	tCartela cartela;
	cartela = LeCartela();

	ImprimeCartela(cartela);

	return 0;
}

tCartela LeCartela(){
	tCartela cartela;
	scanf("%d%*c", &cartela.id);
	scanf("%d%*c", &cartela.colunas);

	int i = 0, j = 0;
	for (; i < cartela.colunas; i++)
		for (j = 0; j < cartela.colunas; j++)
			scanf("%d", &cartela.numeros[j][i]);

	return cartela;
}

void ImprimeCartela(tCartela cartela){
	printf("ID:%d\n", cartela.id);

	int i = 0, j = 0;
	for (; i < cartela.colunas; i++){
		for (j = 0; j < cartela.colunas; j++){
			printf("%03d", cartela.numeros[i][j]);

			if (j + 1 < cartela.colunas) printf("|");
			else printf("\n");
		}
	}
}