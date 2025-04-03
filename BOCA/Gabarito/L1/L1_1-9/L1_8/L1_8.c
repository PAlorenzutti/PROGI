#include <stdio.h>

int main(){
	char c;
	if (scanf("%c", &c) == 1){
		int x = (int)c;
		if ((x > 64 && x < 91) || (x > 96 && x < 123)){
			if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') printf("Vogal");
			else printf("Nao Vogal");
			return 0;
		}
	}
	return 1;
}