#include <stdio.h>
#include <stdlib.h>

int TemComida(int a, int b, int placa[a][b]);
int Print(int a, int b, int placa[a][b]);
int BacteriaComeCome(int a, int b, int placa[a][b], int novaPlaca[a][b], int j, int k);
int RenovaPlaca(int a, int b, int placa[a][b], int novaPlaca[a][b]);

int main(){
	int j, k, i, a, b;
	scanf("%d %d\n", &b, &a);
	int mat[a][b], new[a][b];

	for (j = 0; j < a; j++){
		for (k = 0; k < b; k++){
			scanf("%1d", &mat[j][k]);
			new[j][k] = mat[j][k];
		}
		scanf("%*c");
	}
	
	for (i = 0; TemComida(a, b, mat); i++){
		for (j = 0; j < a; j++)
			for (k = 0; k < b; k++)
				if (mat[j][k] == 1 || mat[j][k] == 9)
					BacteriaComeCome(a, b, mat, new, j, k);
		RenovaPlaca(a, b, mat, new);
	}

	printf("%d", i);

	return 0;
}

int TemComida(int a, int b, int placa[a][b]){
	int i = 0, j = 0;
	for (; i < a; i++)
		for (j = 0; j < b; j++)
			if (placa[i][j] == 9) return 1;
	return 0;
}

int Print(int a, int b, int placa[a][b]){
	int i = 0, j = 0;
	for (; i < a; i++){
		for (j = 0; j < b; j++){
			printf("%c", placa[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int BacteriaComeCome(int a, int b, int placa[a][b], int novaPlaca[a][b], int j, int k){
	if (k + 1 < b)
		if (placa[j][k + 1] == 0)
			novaPlaca[j][k] = 0;
	if (k - 1 >= 0)
		if (placa[j][k - 1] == 0)
			novaPlaca[j][k] = 0;
	if (j - 1 >= 0)
		if (placa[j - 1][k] == 0)
			novaPlaca[j][k] = 0;
	if (j + 1 < a)
		if (placa[j + 1][k] == 0)
			novaPlaca[j][k] = 0;
}

int RenovaPlaca(int a, int b, int placa[a][b], int novaPlaca[a][b]){
	int j = 0, k = 0;
	for (j = 0; j < a; j++) 
		for (k = 0; k < b; k++)
			placa[j][k] = novaPlaca[j][k];
}