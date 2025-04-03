#include <stdio.h>

int main(){
	int n, i = 0;
	scanf("%d", &n);
	int A[n];
	for (; i < n; scanf("%d", &A[i]), i++);

	if (n == 1) printf("NAO");
	else {
		int dif, last = A[1] - A[0];
		for (i = 1; i < n; i++){
			dif = A[i] - A[i-1];
			if (last != dif) break;
			last = dif;
		}

		if (i != n) printf("NAO");
		else printf("RESP:%d", dif);
	}

	return 0;
}