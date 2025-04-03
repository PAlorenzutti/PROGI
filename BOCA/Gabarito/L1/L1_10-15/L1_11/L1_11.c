#include <stdio.h>

int main(){
	int x;
	if (scanf("%d", &x) == 1){
		char months[12][4] = {
			"Jan",
			"Fev",
			"Mar",
			"Abr",
			"Mai",
			"Jun",
			"Jul",
			"Ago",
			"Set",
			"Out",
			"Nov",
			"Dez"
		};
		if (x > 0 && x < 13){
			char msg[4];
			int i;
			for (i = 0; i < 3; i++) msg[i] = months[x-1][i];
			printf("%s.\n", msg);
			return 0;
		}
	}
	printf("Invalido.");
	return 1;
}