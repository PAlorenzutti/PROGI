#include <stdio.h>
#include <stdlib.h>

int TemComida(int a, int b, char placa[a][b]);
int Print(int a, int b, char placa[a][b]);

int main(){
	int j, k, i, a, b;
	scanf("%d %d\n", &b, &a);
	char mat[a][b], new[a][b];

	for (j = 0; j < a; j++){
		for (k = 0; k < b; k++){
			scanf("%c", &mat[j][k]);
			new[j][k] = mat[j][k];
		}
		scanf("%*c");
	}
	
	for (i = 0; TemComida(a, b, mat); i++){
		for (j = 0; j < a; j++){
			for (k = 0; k < b; k++){
				if (mat[j][k] == '1' || mat[j][k] == '9'){
					if (k + 1 < b)
						if (mat[j][k + 1] == '0')
							new[j][k] = '0';
					if (k - 1 >= 0)
						if (mat[j][k - 1] == '0')
							new[j][k] = '0';
					if (j - 1 >= 0)
						if (mat[j - 1][k] == '0')
							new[j][k] = '0';
					if (j + 1 < a)
						if (mat[j + 1][k] == '0')
							new[j][k] = '0';
				}
			}
		}
		for (j = 0; j < a; j++) 
			for (k = 0; k < b; k++)
				mat[j][k] = new[j][k];
	}

	printf("%d", i);

	return 0;
}

int TemComida(int a, int b, char placa[a][b]){
	int i = 0, j = 0;
	for (; i < a; i++)
		for (j = 0; j < b; j++)
			if (placa[i][j] == '9') return 1;
	return 0;
}

int Print(int a, int b, char placa[a][b]){
	int i = 0, j = 0;
	for (; i < a; i++){
		for (j = 0; j < b; j++){
			printf("%c", placa[i][j]);
		}
		printf("\n");
	}
	return 0;
}