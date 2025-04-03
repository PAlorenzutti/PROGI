#include <stdio.h>

int main(){
	int t;
	char u;
	if (scanf("%d %c", &t, &u) == 2){
		if (u == 'f' || u == 'F'){
			float c = (t - 32)/1.8;
			printf("%0.2f (C)\n", c);
		}
		else if (u == 'c' || u == 'C'){
			float f = (t * 1.8) + 32;
			printf("%0.2f (F)\n", f);
		}
		else return 1; 
		return 0;
	}
	return 1;
}