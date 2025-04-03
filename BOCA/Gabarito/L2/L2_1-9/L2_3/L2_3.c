#include <stdio.h>

int main(){
	int n;
	int max = 0, min = 0, par = 0, imp = 0;
	float avg = 0;
	int m = 0;
	if (scanf("%d", &n) == 1){
		int i;
		for (i = 0; i < n; i++) {
			scanf("%d ", &m);
			if (m > max) max = m;
			if (m < min || (i == 0)) min = m;
			if (m % 2 == 0) par++;
			else imp++;
			avg += m;
		}
		avg = avg/n;
		printf("%d %d %d %d %0.6f", max, min, par, imp, avg);
	}
	return 0;
}