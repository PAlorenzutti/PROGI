#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pID;
	int mID;
	int length;
	char text[9];
	int eID;
} tProduto;

int main(){
	int n;
	scanf("%d", &n);

	char c;
	int i = 0, j = 0;
	tProduto msg = { 0, 0, 0, "", 0 };
	for (; i < n; i++) {
		scanf("%d%*c", &msg.mID);
		scanf("%d%*c", &msg.pID);

		scanf("%c", &c);
		msg.length = c - '0';
		for (j = 0; j < msg.length; j++) 
			scanf("%c", &msg.text[j]);
		for (; j < 9; j++)
			scanf("%*c");

		scanf("%*c%d", &msg.eID);
		printf("PCT: %d,%d,%d,%s,%d\n", msg.mID, msg.pID, msg.length, msg.text, msg.eID);
		for (j = 0; j < 9; j++)
			msg.text[j] = '\0';
	}

	return 0;
}