#include <stdio.h>
#include <math.h>

int main(){
	int a, b;
	if (scanf("%d %d", &a, &b) == 2){
		float sum = sqrt(a) + sqrt(b);
		printf("%.2f\n", sum);
		return 0;
	}
	return 1;
}