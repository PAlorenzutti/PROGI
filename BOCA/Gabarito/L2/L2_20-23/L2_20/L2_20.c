#include <stdio.h>

int main(){
	int i, e, f, state = 0, lastState, peak = 0, vale = 0;
	float a, b, c, d, y, last;
	scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);

	for (i = e; i <= f; i++) {
		y = a*i*i*i + b*i*i + c*i + d;
		printf("\nPara x = %d, y = %.2f\n", i, y);
		//printf("%f + %f + %f + %f = %f\n", a*i*i*i, b*i*i, c*i, d, y);
		state = (y < last) ? -1 : 1;

		if (i > (e + 1) && lastState != 0) {
			if (state < lastState) { peak = 1; printf("\n\nPico em x=%d\n", i-1); } 
			if (state > lastState) { vale = 1; printf("Vale em x=%d\n", i-1); }
		}
		lastState = state;
		last = y;
	}

	if (peak == 0) printf("Nao ha pico\n");
	if (vale == 0) printf("Nao ha vale");
	
	return 0;
}