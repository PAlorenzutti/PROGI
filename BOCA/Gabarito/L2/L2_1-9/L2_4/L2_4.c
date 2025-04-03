#include <stdio.h>

int main(){
	int max = 0, imp = 0;
	float avg = 0;
	int m = 0;
	int i;
	for (i = 1; ; i++) {
		scanf("%d ", &m);
		if (m == 0) break;

		if (m > max) max = m;
		avg += m;
		printf("%d %0.6f\n", max, avg/i);
	}
	return 0;
}