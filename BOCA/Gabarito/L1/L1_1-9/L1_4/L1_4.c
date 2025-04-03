#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main(){
	float r;
	if (scanf("%f", &r) == 1){
		float area = PI*r*r;
		float lesserArea = area/2;
		float newRadius = sqrt(lesserArea/PI);
		printf("%.2f %.2f\n", area, newRadius);
		return 0;
	}
	return 1;
}