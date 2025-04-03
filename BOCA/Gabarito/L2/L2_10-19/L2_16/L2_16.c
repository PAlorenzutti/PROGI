#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 32000, loop = 0, min = 32000, first = -1, last = -1, index = 0;
	char c;

	do {
		if (scanf("%d", &i) != 1) {
			scanf("%*c");
			loop++;
		}
		else {
			if (loop == 0) {
				if (min > i) min = i;
			}
			else {
				if (i == min) {
					if (first == -1) first = index;
					last = index;
				} 
				index++;
			}
		}
	} while(loop != 2);

	if (first == -1) {
		first = index;
		last = index;
	}
	printf("%d %d %d", min, first, last);

	return 0;
}