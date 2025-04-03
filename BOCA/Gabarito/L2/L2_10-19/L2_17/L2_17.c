#include <stdio.h>

int main(){
	int i, n;
	char c;

	scanf("%d %d ", &i, &n);

	while (c != '.'){
		scanf("%c", &c);

		if (i == 1) {
			if (c < 123 && c > 96){
				if (c + n%26 >= 123) c += - 26 + (n%26);
				else c += (n%26);
			}
		}
		else if (i == 2) {
			if (c < 123 && c > 96){
				if (c - n%26 <= 96) c += + 26 - (n%26);
				else c -= (n%26);
			}
		}
		else { printf("Operacao invalida."); break; }

		printf("%c", c);
	}
	return 0;
}