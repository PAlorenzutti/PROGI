#include <stdio.h>
#include <math.h>

int main(){
	int min = 0, max = 0;
	scanf("%d %d", &min, &max);

	int i;
	for (; min <= max; min++)
		for (i = 1; i <= 10; i++) 
			printf("%d x %d = %d\n", min, i, min*i);
	return 0;
}