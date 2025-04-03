#include <stdio.h>

int main(){
	int n, m;
	if (scanf("%d %d", &n, &m) == 2){
		printf("RESP:");
		for (n = n + 1; n < m; n++) 
			if (n % 2 == 0) 
				printf("%d ", n);
	}
	return 0;
}