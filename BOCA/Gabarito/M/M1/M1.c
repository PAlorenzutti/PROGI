#include <stdio.h>

int main(){
	int a, b;
	if (scanf("%d %d", &a, &b) == 2){
		printf("%d,%d", b, a);
		return 0;
	}
	return 1;
}