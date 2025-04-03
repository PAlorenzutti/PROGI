#include <stdio.h>
#include <math.h>

int main(){
	int min = 0, max = 0;
	scanf("%d %d", &min, &max);

	int i;
	int ab, cd, ef;
	for (min = min + 1; min < max; min++){
		ab = min / 100;
		cd = min - ab * 100;
		ef = ab + cd;
		if (ef*ef == min) printf("%d\n", min);
	}
	return 0;
}