#include <stdio.h>

int subtracter(int n, int i){
	if (n >= i) return i;
	else return subtracter(n, i - n);
}

int main(){
	int n, i;
	if (scanf("%d %d", &n, &i) == 2){
		int a = subtracter(n, i);
		printf("RESP:%d", a);
		return 0;
	}
	return 1;
}

/*

int main(){
	int n, i, r;
	if (scanf("%d %d", &n, &i) == 2){
		r = i%n;
		if (r == 0) r = n;
		printf("%d", r);
	}
	return 0;
}

*/