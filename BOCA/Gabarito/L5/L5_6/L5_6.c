#include <stdio.h>

int isInto(int A[], int B[], int a, int b);

int main(){
	int n, m, i = 0;
	scanf("%d", &n);
	int A[n];
	for (i = 0; i < n; scanf("%d", &A[i]), i++);

	scanf("%d", &m);
	int B[m];
	for (i = 0; i < m; scanf("%d", &B[i]), i++);

	int amount = isInto(A, B, n, m);
	if (amount == n) printf("TODOS");
	else if (amount == 0) printf("NENHUM");
	else printf("PARCIAL");

	return 0;
}

int isInto(int A[], int B[], int a, int b){
	int i = 0, j = 0, amount = 0;
	for (; i < b; i++){
		for (j = 0; j < a; j++){
			if (A[j] == B[i]){
				amount++;
				break;
			}
		}
	}
	return amount;
}