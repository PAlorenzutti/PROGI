#include <stdio.h>
#include <math.h>

int main(){
	int n, i;
	scanf("%d", &n);
	for (i = 2; i < n; i++) if (n%i == 0) {
		printf("Nao Primo");
		return 0;
	}
	printf("Primo");
	return 0;
}