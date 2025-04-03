#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(){
	int n, i = 0;
	scanf("%d", &n);
	int A[n];
	for (; i < n; scanf("%d", &A[i]), i++);

	TrocaParEImpar(A, n);

	return 0;
}

void TrocaParEImpar(int vet[], int qtd){
	int t = 0, i = 1;
	for (; i < qtd; i += 2){
		t = vet[i-1];
		vet[i-1] = vet[i];
		vet[i] = t;
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