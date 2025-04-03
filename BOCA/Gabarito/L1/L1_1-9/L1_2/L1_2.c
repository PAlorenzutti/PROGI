#include <stdio.h>

int main(){
	float w, h;
	if (scanf("%f %f", &w, &h) == 2){
		float sum = 2*w + 2*h;
		printf("%.2f\n", sum);
		return 0;
	}
	return 1;
}