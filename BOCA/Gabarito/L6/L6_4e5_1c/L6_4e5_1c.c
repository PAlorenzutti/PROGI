#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pID;
	int mID;
	int length;
	char text[9];
	int eID;
} tProduto;

int checkError(tProduto p);
void printMessage(tProduto *all, int n);
void arrangeArray(tProduto *all, int n);

int main(){
	int n;
	scanf("%d", &n);

	char c;
	int i = 0, j = 0;
	tProduto msg = { 0, 0, 0, "", 0 };
	tProduto all[n];

	for (i = 0; i < n; i++)
		all[i] = msg;

	for (i = 0; i < n; i++) {
		scanf("%d%*c", &msg.mID);
		scanf("%d%*c", &msg.pID);

		scanf("%c", &c);
		msg.length = c - '0';
		for (j = 0; j < msg.length; j++) 
			scanf("%c", &msg.text[j]);
		for (; j < 9; j++)
			scanf("%*c");

		scanf("%*c%d", &msg.eID);
		all[i] = msg;
		for (j = 0; j < 9; j++)
			msg.text[j] = '\0';
	}

	arrangeArray(all, n);
	printMessage(all, n);

	return 0;
}

int checkError(tProduto p){
	int i = 0, sum = p.pID + p.mID + p.length;
	for (; i < p.length; i++)
		sum += p.text[i];
	return p.eID == sum;
}

void printMessage(tProduto *all, int n){
	int i = 0;
	for (; i < n; i++){
		if (i > 0 && all[i].mID != all[i - 1].mID)
			printf("\n");

		if (checkError(all[i])) 
			printf("%s", all[i].text);
		else 					
			printf("##FALHA##");

	}
}

void arrangeArray(tProduto *all, int n){
	int i = 0, j = 1;
	tProduto t;
	for (; i < n; i++){
		for (j = i + 1; j < n; j++){
			if (all[j].mID < all[i].mID || (all[j].mID == all[i].mID && all[j].pID < all[i].pID)){
				t = all[j];
				all[j] = all[i];
				all[i] = t;
			}
		}
	}
}