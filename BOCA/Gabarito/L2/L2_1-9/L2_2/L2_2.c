#include <stdio.h>

int main(){
	int n, m;
	if (scanf("%d %d", &n, &m) == 2){
		for (n = n + 1; n < m; n++) 
			if (n % 3 == 0 || n % 4 == 0 || n % 7 == 0) 
				printf("%d ", n);
	}
	return 0;
}