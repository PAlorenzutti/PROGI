#include <stdio.h>

int getDif(int altura1, int altura2);

int main(){
	int n;
	scanf("%d", &n);

	int alturas[n];
	int i = 0;
	for (; i < n; scanf("%d", &alturas[i]), i++);

	int max = -1;
	for (i = 1; i < n; i++)
		if (getDif(alturas[i-1], alturas[i]) > max) 
			max = getDif(alturas[i-1], alturas[i]);

	for (i = 1; i < n; i++)
		if (getDif(alturas[i-1], alturas[i]) == max) 
			printf(" (%d %d)", i-1, i);

	if (n == 1) printf("IMPOSSIVEL");

	return 0;
}

int getDif(int altura1, int altura2){
	int dif = altura1 - altura2;
	if (dif < 0) dif *= -1;
	return dif;
}