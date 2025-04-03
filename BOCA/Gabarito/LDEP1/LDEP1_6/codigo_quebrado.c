#include <stdio.h>

int main(){
	
	int l, c, i, j;
	int soma = 0, atual;
	int ant = 0;

	scanf("%d %d", &l, &c);
	
	int somas[l];
	for (i = 0; i < c; i++){
		for(j = 0; j < l; j++){
			scanf("%d", &atual);
			soma += atual;
		}
		somas[i] = soma;
		soma = 0;
	}

	int total = 0;
	for (i = 0; i < l; i++){
		printf("%d\n", somas[i]);
		total += somas[i];
	}
	printf("%d\n", total);

	return 0;
}
