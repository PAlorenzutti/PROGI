#include <stdio.h>

int main(){
	float a;
	if (scanf("%f", &a) == 1) {
		int integer = a;
		float real = a - integer;
		printf("INTEIRO:%d,REAL:%.2f", integer, real);
		return 0;
	}
	return 1;
}