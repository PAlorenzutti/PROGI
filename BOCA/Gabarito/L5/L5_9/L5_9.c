#include <stdio.h>

void InverteVetor(int* vet, int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(){
	int n, i = 0;
	scanf("%d", &n);
	int A[n];
	for (; i < n; scanf("%d", &A[i]), i++);

	InverteVetor(A, n);

	return 0;
}

void InverteVetor(int* vet, int qtd){
	int i, j, t;
	for (i = 0, j = qtd - 1; i < j; i++, j--){
		t = vet[i];
		vet[i] = vet[j];
		vet[j] = t;
	}
	ImprimeDadosDoVetor(vet, qtd);
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