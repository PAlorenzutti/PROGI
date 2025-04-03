#include <stdio.h>

int main(){
	char c;
	printf("RESP:");
	do {
		scanf("%c", &c);
		if (c != ' ') printf("%c", c);
		if (c == '!' || c == '.' || c == '?') break;
	} while(1);

	return 0;
}