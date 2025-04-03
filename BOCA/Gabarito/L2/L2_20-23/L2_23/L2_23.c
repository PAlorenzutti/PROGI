#include <stdio.h>

int main(){
	char c = ' ';
	int expectedCloses = 0;
	printf("RESP:");
	while(!(c == '.' && expectedCloses == 0)){
		scanf("%c", &c);
		if (c == ')') expectedCloses--;
		if (expectedCloses > 0) printf("%c", c);
		if (c == '(') expectedCloses++;
	}

	return 0;
}