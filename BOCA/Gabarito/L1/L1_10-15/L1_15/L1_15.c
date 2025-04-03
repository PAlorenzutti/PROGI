#include <stdio.h>

int square(int n, int i, int result){
	if (i == 0) return result;
	return square(n, i-1, n*result);
}

int main(){
	int num, a;
	if (scanf("%d %d", &num, &a) == 2){
		if (num >= 0 && num <= 99999){
			int sqr = square(10, a - 1, 1);
			int isEven = (num/sqr)%2;
			const char* msg = (isEven == 0) ? "PAR" : "IMPAR";
			printf("%s", msg);
			return 0;
		}
	}
	return 1;
}