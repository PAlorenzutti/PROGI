#include <stdio.h>
#include <math.h>

double sone(){
	int i, j;
	double r = 0.0, sum = 0.0;
	for (i = 1, j = 1; i <= 99; i += 2, j++) {
		r += (double)i/j;
	}
	return r;
}

double stwo(){
	int i;
	double sqr = 1, sum = 0.0, r = 0.0;
	for (i = 1; i <= 50; i++) {
		sqr *= 2;
		r += sqr/(51 - i);
	}
	return r;
}

double sthree(){
	double i, r = 0.0;
	for (i = 1; i <= 10; i++) r += 1.0/i;
	return r;
}

int main(){
	int m = 0;
	scanf("%d", &m);

	double result = 0.0;
	if (m == 1)	result = sone();
	else if (m == 2) result = stwo();
	else if (m == 3) result = sthree();
	printf("%0.6f", result);

	return 0;
}