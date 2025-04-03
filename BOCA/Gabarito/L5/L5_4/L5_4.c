#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int vetor[n];
	int i = 0;
	for (; i <= n + 1; scanf("%d", &vetor[i]), i++);

	int b = vetor[n+1], a = vetor[n], in = 0;
	for (i = 0; i < n; i++)
		if (vetor[i] >= a && vetor[i] <= b) in++;

	printf("%d %d", in, n-in);

	return 0;
}