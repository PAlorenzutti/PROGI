#include <stdio.h>

int main(){
	int h1 = 0, m1 = 0, h2 = 0, m2 = 0, h3 = 0, m3 = 0;
	if (scanf("%d:%d", &h1, &m1) == 2){
		if (h1 > 23 || h1 < 0 || m1 > 59 || m1 < 0);
		else if (scanf("%d:%d", &h2, &m2) == 2){
			if (h2 > 23 || h2 < 0 || m2 > 59 || m2 < 0);
			else {
				m3 = m1 + m2;
				if (m3 > 59) { h3++; m3 -= 60; }

				h3 += h1 + h2;
				if (h3 > 23) { h3 -= 24; printf("+1D(%d:%d)", h3, m3); }
				else printf("(%d:%d)", h3, m3);
			}
		}
	}
	return 0;
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