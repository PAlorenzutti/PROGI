#include <stdio.h>
#include <math.h>

int main(){
	int min = 0, max = 0;
	scanf("%d %d", &min, &max);
	int i;
	printf("RESP:");
	for (min = min + 1; min < max; min++) {
		for (i = 2; i <= min; i++){
			if (i == min) printf("%d ", min);
			if (min % i == 0) break;
		}
	}
	return 0;
}