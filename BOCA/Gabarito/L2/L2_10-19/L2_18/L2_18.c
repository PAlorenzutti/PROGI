#include <stdio.h>

int main(){
	int m = 0, n = 0, x, y, i, j, t, max = -32e5;

	scanf("%d %d", &m, &n);

	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			scanf("%d", &t);
			if (t > max) {
				max = t;
				x = i;
				y = j;
			}
		}
	}
	printf("%d (%d, %d)", max, x, y);
	
	return 0;
}