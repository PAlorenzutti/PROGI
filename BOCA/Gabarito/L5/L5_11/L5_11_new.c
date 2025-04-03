#include <stdio.h>
//not working yet!!!!

typedef struct {
	int value;
	char name;
} slot;

void OrdenaCrescente(slot vet[], int qtd);
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

	slot C[n + m];
	for (i = 0; i < n + m; i++){
		if (i < n){
			C[i].value = A[i];
			C[i].name = 'A';
		}
		else if (n - i < m)	{
			C[i].value = B[n - i];
			C[i].name = 'B';
		}
	}

	OrdenaCrescente(C, m + n);
	for (i = 0; i < m + n; printf("%c", C[i].name), i++);

	return 0;
}

void OrdenaCrescente(slot vet[], int qtd){
	int i, j;
	slot t;
	for (i = 0; i < qtd; i++){
		for (j = i + 1; j < qtd; j++) {
			if (vet[i].value > vet[j].value){
				t = vet[j];
				vet[j] = vet[i];
				vet[i] = t;
			}
		}
	}
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