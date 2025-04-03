#include <stdio.h>

int main(){
	int a, b;
	if (scanf("%d %d", &a, &b) == 2){
		if (a == b) printf("N1 = N2");
		else if (a > b) printf("N1 = %d\n", a);
		else if (a < b) printf("N2 = %d\n", b);
		return 0;
	}
	return 1;
}