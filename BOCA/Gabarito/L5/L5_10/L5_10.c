#include <stdio.h>

void OrdenaCrescente(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(){
	int n, i = 0;
	scanf("%d", &n);
	int A[n];
	for (; i < n; scanf("%d", &A[i]), i++);

	OrdenaCrescente(A, n);

	return 0;
}

void OrdenaCrescente(int vet[], int qtd){
	int i, j, t;
	for (i = 0; i < qtd; i++){
		for (j = i + 1; j < qtd; j++) {
			if (vet[i] > vet[j]){
				t = vet[j];
				vet[j] = vet[i];
				vet[i] = t;
			}
		}
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