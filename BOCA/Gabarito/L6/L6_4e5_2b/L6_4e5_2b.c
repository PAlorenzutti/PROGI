#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int colunas;
	int numeros[7][7];
} tCartela;

typedef struct {
	int amount;
	tCartela cartelas[100];
} tPartida;

void ImprimeCartela(tCartela cartela);
tCartela LeCartela();
tPartida LeCartelasPartida();
void ImprimeInvCartelasPartida(tPartida partida);

int main(){
	tPartida partida;
	partida = LeCartelasPartida();

	ImprimeInvCartelasPartida(partida);

	return 0;
}

tPartida LeCartelasPartida(){
	tPartida partida;
	scanf("%d%*c", &partida.amount);

	int i = 0;
	for (; i < partida.amount; i++)
		partida.cartelas[i] = LeCartela();

	return partida;
}

void ImprimeInvCartelasPartida(tPartida partida){
	int i = partida.amount - 1;
	for (; i >= 0; i--)
		ImprimeCartela(partida.cartelas[i]);
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