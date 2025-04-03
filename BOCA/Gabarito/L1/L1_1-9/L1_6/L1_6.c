#include <stdio.h>

int main(){
	int a, b;
	if (scanf("%d %d", &a, &b) == 2){
		float m = (a + b)/2.0;
		if (m >= 7.0) printf("%.1f - Aprovado\n", m);
		else if (m < 5.0) printf("%.1f - Reprovado\n", m);
		else printf("%.1f - De Recuperacao\n", m);
		return 0;
	}
	return 1;
}