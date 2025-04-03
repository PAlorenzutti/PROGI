#include <stdio.h>

int main(){
	int i = 101, sumN = 0, sumP = 0, nNeg = 0, nPos = 0;
	do {
		scanf("%d ", &i);
		if (i < 0 && i > -100){
			sumN += i;
			nNeg++;
		}
		else if (i > 0 && i < 100){
			sumP += i;
			nPos++;
		}

		if (i == 101) break;
		i = 101;
	} while(1);

	printf("%d %d %d %d", nNeg, nPos, sumN, sumP);

	return 0;
}