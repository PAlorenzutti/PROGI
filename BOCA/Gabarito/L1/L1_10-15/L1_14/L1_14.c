#include <stdio.h>

void switcher(int* n, int* m){
	int t = *n;
	*n = *m;
	*m = t;
}

int tracker(int min, int max, int a){
	if (a >= min && a <= max) return 1;
	else return 0;
}

int main(){
	int x, y, z, w, a, b;
	if (scanf("%d %d %d %d %d %d", &x, &y, &z, &w, &a, &b) == 6){
		if (x > z) switcher(&x, &z);
		if (y > w) switcher(&y, &w);
		if (tracker(x, z, a) && tracker(y, w, b) == 1) printf("Dentro");
		else printf("Fora");
	}
	return 0;
}

/*

int main(){
	int x, y, z, w, a, b, t;
	if (scanf("%d %d %d %d %d %d", &x, &y, &z, &w, &a, &b) == 6){
		if (x > z) { t = z; z = x; x = t; }
		if (y > w) { t = w; w = y; y = t; }
		if (x <= a && z >= a && y <= b && w >= b) printf("Dentro");
		else printf("Fora");
	}
	return 0;
}











*/