#include <stdio.h>

int main(){
	int n, i, a = 0, lookFor = 0, numEq;
	scanf("%d", &n);
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, b;

	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (i == 1) a1 = a;
		else if (i == 2) a2 = a;
		else if (i == 3) a3 = a;
		else if (i == 4) a4 = a;
		else if (i == 5) a5 = a;
		else if (i == 6) a6 = a;
		else if (i == 7) a7 = a;
		else if (i == 8) a8 = a;
		else if (i == 9) a9 = a;
	}

	char c;
	scanf(" %c", &c);
	c = ' ';
	while (c != '"'){
		scanf("%c", &c);
		if (lookFor == 1){
			i = c - 48;
			if (i <= n && i > 0){
				b = (i == 1) ? a1 : (i == 2) ? a2 : (i == 3) ? a3 :
				 	(i == 4) ? a4 : (i == 5) ? a5 : (i == 6) ? a6 :
				 	(i == 7) ? a7 : (i == 8) ? a8 : a9;
				printf("%d", b);
			}
			else printf("ERRO");
			
			lookFor = 0;
		}
		else if (c == '%') lookFor = 1;
		else if (c != '"') printf("%c", c);
	}

	return 0;
}