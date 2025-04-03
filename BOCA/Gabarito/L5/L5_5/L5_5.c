#include <stdio.h>

int main(){
	int n, x;
	scanf("%d %d", &x, &n);

	int vetor[n];
	int i = 0;
	for (; i < n; scanf("%d", &vetor[i]), i++);

	for (i = 0; i < n; i++){
		if (vetor[i] == x) break;
	}

	printf("RESP:%d", i);

	return 0;
}