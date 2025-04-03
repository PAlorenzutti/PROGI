#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int colunas;
	int numeros[7][7];
	int marcadas[7][7];
} tCartela;

typedef struct {
	int amount;
	tCartela cartelas[100];
} tPartida;

void ImprimeCartela(tCartela cartela);
tCartela LeCartela();

tPartida LeCartelasPartida();
void ImprimeInvCartelasPartida(tPartida partida);

void JogaPartida(tPartida partida);
tPartida ResetaPartida(tPartida partida);

tCartela MarcaCartela(tCartela cartela, int num);
int VenceuCartela(tCartela cartela);
tCartela ResetaCartela(tCartela cartela);

int Repetida(tPartida partida, tCartela cartela);

int main(){
	tPartida partida;
	int qtdPartidas, i;
	partida = LeCartelasPartida();

	scanf ("%d", &qtdPartidas);
	for (i = 0; i < qtdPartidas; i++){
		if ( i!=0 ) printf("\n");
			printf("PARTIDA %d\n", i+1);

		partida = ResetaPartida(partida);
		JogaPartida(partida);
	}

	return 0;
}

void JogaPartida(tPartida partida){
	int n, i = 0, v = 0, venceu = 0;
	while(scanf("%d", &n) && n != -1){
		for (i = 0; i < partida.amount; i++){
			partida.cartelas[i] = MarcaCartela(partida.cartelas[i], n);
			if (VenceuCartela(partida.cartelas[i]) && venceu == 0) {
				if (v == 0) printf("COM VENCEDOR\n");
				ImprimeCartela(partida.cartelas[i]);
				v++;
			}
		}
		if (v > 0) venceu = 1;
		scanf("%*c");
	}
	if (venceu == 0) printf("SEM VENCEDOR\n");
}



tPartida ResetaPartida(tPartida partida){
	int i = 0;
	for (; i < partida.amount; i++)
		partida.cartelas[i] = ResetaCartela(partida.cartelas[i]);
	return partida;
}



tCartela MarcaCartela(tCartela cartela, int num){
	int i = 0, j = 0;
	for (; i < cartela.colunas; i++)
		for (j = 0; j < cartela.colunas; j++)
			if (cartela.numeros[i][j] == num)
				cartela.marcadas[i][j] = 1;
	return cartela;
}



int VenceuCartela(tCartela cartela){
	int i = 0, j = 0;
	for (; i < cartela.colunas; i++)
		for (j = 0; j < cartela.colunas; j++)
			if (cartela.marcadas[i][j] == 0) 
				return 0;
	return 1;
}



tCartela ResetaCartela(tCartela cartela){
	int i = 0, j = 0;
	for (; i < cartela.colunas; i++)
		for (j = 0; j < cartela.colunas; j++)
			cartela.marcadas[i][j] = 0; 
	return cartela;
}



tPartida LeCartelasPartida(){
	tPartida partida;
	scanf("%d%*c", &partida.amount);

	int i = 0;
	for (; i < partida.amount; i++){
		partida.cartelas[i] = LeCartela();
		partida.cartelas[i] = ResetaCartela(partida.cartelas[i]);
	}

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