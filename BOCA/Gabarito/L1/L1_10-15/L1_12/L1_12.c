#include <stdio.h>

void switcher(int* N, int* M, char* I, char* J){
	int n = *N;
	*N = *M;
	*M = n;
	char i = *I;
	*I = *J;
	*J = i;
}

int main(){
	int a, b, c;
	if (scanf("%d %d %d", &a, &b, &c) == 3){
		char x = '1', y = '2', z = '3';

		if (a > b) switcher(&a, &b, &x, &y);
		if (a > c) switcher(&a, &c, &x, &z);
		if (b > c) switcher(&b, &c, &y, &z);

		printf("N%c = %d, N%c = %d, N%c = %d", x, a, y, b, z, c);
		return 0;
	}
	return 1;
}