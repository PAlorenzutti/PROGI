#include <stdio.h>

int main(){
	char c;
	if (scanf("%c", &c) == 1){
		if (c > 96 && c < 123){
			int ascii = c - 32;
			char upper = (char) ascii;
			printf("%c(%d)", upper, ascii);
			return 0;
		}
		else if (c > 64 && c < 91) printf("A letra deve ser minuscula!");
		else printf("Nao e letra!");
	}
	return 1;
}