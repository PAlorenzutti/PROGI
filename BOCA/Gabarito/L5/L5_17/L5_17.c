#include <stdio.h>
#include <stdlib.h>

//find char and put on string?

int main(){
	char text[500][500];
	char word[500];

	int i = 0, j = 0;
	for (i = 0; i < 500; i++)
		for (j = 0; j < 500; j++) 
			text[i][j] = '\0';

	for (j = 0; word[j]; j++) 
		word[j] = '\0';

	for (i = 0; i < 500; i++){
		scanf("%[a-zA-Z]", &word);
		scanf("%*c");
		for (j = 0; word[j]; j++) text[i][j] = word[j];
		for (j = 0; word[j]; j++) word[j] = '\0';
	}
	
	printf(" ");
	for (i = 499; i >= 0; i--){
		if (text[i][0] != '\0') printf("%s ", text[i]);
	}

	return 0;
}