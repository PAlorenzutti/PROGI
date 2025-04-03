#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, j, k, i, c = 0, a, b;
	scanf("%d", &n);

	scanf("%d %d\n", &b, &a);
	char mat[a][b], new[a][b];

	for (j = 0; j < a; j++){
		for (k = 0; k < b; k++){
			scanf("%c", &mat[j][k]);
			if (mat[j][k] == '0') c++;
			new[j][k] = mat[j][k];
		}
		scanf("%*c");
	}

	char o;
	for (i = 0; i < n; i++){
		for (j = 0; j < a; j++){
			for (k = 0; k < b; k++){
				o = mat[j][k];
				if (o == '0'){
					if (k + 1 < b)
						if (mat[j][k + 1] == '1')
							new[j][k] = '1';
					if (k - 1 >= 0)
						if (mat[j][k - 1] == '1')
							new[j][k] = '1';
					if (j - 1 >= 0)
						if (mat[j - 1][k] == '1')
							new[j][k] = '1';
					if (j + 1 < a)
						if (mat[j + 1][k] == '1')
							new[j][k] = '1';
				}
			}
		}
		for (j = 0; j < a; j++) 
			for (k = 0; k < b; k++)
				mat[j][k] = new[j][k];
	}

	i = 0;
	for (j = 0; j < a; j++)
		for (k = 0; k < b; k++)
			if (mat[j][k] == '0') i++;

	printf("%d %d", c, i);

	return 0;
}