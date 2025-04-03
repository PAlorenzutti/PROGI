#include <stdio.h>
#include <math.h>

int main(){
	float pi = 0;
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		pi += 6.0/(i*i);
	}
	printf("%0.6f", sqrt(pi));
	return 0;
}