#include <stdio.h>

int main(){
	float x, y, xl, yl;
	if (scanf("%f %f %f %f", &x, &y, &xl, &yl) == 4){
		float w = xl - x;
		float h = yl - y;
		float sum = 2*h + 2*w;
		printf("%.2f\n", sum);
		return 0;
	}
	return 1;
}