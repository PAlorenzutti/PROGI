#include <stdio.h>

int main(){
	int n, soma;
	scanf("%d", &n);

	soma = n;
	while (n > 9) {
		soma = 0;
		while (n > 9) {
			soma += n%10;
			n /= 10;
		}
		soma += n;
		n = soma;
	}
	printf("RESP:%d", soma);

	return 0;
}