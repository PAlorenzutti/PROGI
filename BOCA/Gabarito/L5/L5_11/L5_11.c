#include <stdio.h>

int hasUsed(int vec[], int index, int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(){
	int n, i = 0;
	scanf("%d", &n);
	int A[n];
	for (; i < n; scanf("%d", &A[i]), i++);

	int m;
	scanf("%d", &m);
	int B[m];
	for (i = 0; i < m; scanf("%d", &B[i]), i++);

	int usedA[n], usedB[m];
	for (i = 0; i < n; usedA[i] = -1, i++);
	for (i = 0; i < m; usedB[i] = -1, i++);

	int min = 32e5, index = 0, Aused = 0, Bused = 0;
	char c;
	for (; Aused + Bused < n + m; printf("%c", c), min = 32e5, c = 'T'){
		for (i = 0; i < n; i++) {
			if (min > A[i] && !hasUsed(usedA, i, n)){
				min = A[i];
				index = i;
				c = 'A';
			}
		}

		for (i = 0; i < m; i++) {
			if (min > B[i] && !hasUsed(usedB, i, m)){
				min = B[i];
				index = i;
				c = 'B';
			}
		}

		if (c == 'A'){
		 	usedA[Aused] = index;
		 	Aused++;
		}
		else{
			usedB[Bused] = index;
			Bused++;	
		} 
	}

	return 0;
}

int hasUsed(int vec[], int index, int qtd){
	int i = 0;
	for (; i < qtd; i++) {
		if (vec[i] == index) return 1;
	}
	return 0;
}

void ImprimeDadosDoVetor(int vet[], int qtd){
	int i = 0;
	printf("{");
	for (; i < qtd - 1; i++)
		printf("%d, ", vet[i]);
	if (qtd != 0)
		printf("%d", vet[qtd - 1]);
	printf("}");
}