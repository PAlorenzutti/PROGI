#include <stdio.h>

int main(){
	char c;
	do {
		scanf("%c", &c);
		if (c < 123 && c > 96) c -= 32;
		printf("%c", c);
		if (c == '!' || c == '.' || c == '?') break;
	} while(1);

	return 0;
}