#include <stdio.h>

int main(){
	int x;
	if (scanf("%d", &x) == 1){
		int rest = x%2;
		const char* msg = (rest == 0) ? "Par" : "Impar";
		printf(msg);
		return 0;
	}
	else return 1;
}