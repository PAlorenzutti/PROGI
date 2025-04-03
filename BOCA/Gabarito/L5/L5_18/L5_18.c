#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);

	int mat1[10][10], mat2[10][10], res[10][10];
	int i = 0, j = 0, k = 0, m = 0, a, b, c, d, r = 0;
	for (; i < n; i++){
		scanf("%d %d", &a, &b);
		for (j = 0; j < b; j++) {
			for (k = 0; k < a; k++) {
				scanf("%d", &mat1[j][k]);
			}
		}

		scanf("%d %d", &c, &d);
		for (j = 0; j < d; j++){
			for (k = 0; k < c; k++){ 
				scanf("%d", &mat2[j][k]);
			}
		}

		if (a == d){
			for (j = 0; j < b; j++) {
				for (k = 0, r = 0; k < c; k++, r = 0) {
					for (m = 0; m < d; m++) {
						r += mat1[j][m] * mat2[m][k];
					}
					printf("%d", r);
					if (k + 1 != c) printf(" ");
				}
				printf("\n");
			}
		} else printf("IMPOSSIVEL\n");
		printf("\n");
	}

	return 0;
}