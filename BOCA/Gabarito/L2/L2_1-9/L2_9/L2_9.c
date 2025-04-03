#include <stdio.h>
#include <math.h>

int main(){
	int min = 0, max = 0;
	scanf("%d %d", &min, &max);

	int i, temp, hasPrime;
	for (min = min + 1; min < max; min++) {
		hasPrime = 0;

		for (i = 2; i <= min; i++){	
			if (i == min) { 									printf("%d\n", min);
				for (temp = min * 2; temp < max; temp += min) 		printf("%d ", temp);
				if (min * 2 >= max) 								printf("*");
				printf("\n");
			}

			if (min % i == 0) break;
		}
	}
	return 0;
}