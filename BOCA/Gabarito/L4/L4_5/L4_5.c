#include <stdio.h>
#include <math.h>

typedef struct{
	int x;
	int y;
} tPonto;

tPonto Ponto(int x, int y);
tPonto GetPonto();
void PrintPonto(tPonto p);
float Distance(tPonto p, tPonto q);

int main()
{
	int n;
	scanf("%d", &n);

	int i = 0;
	tPonto p, lastP;
	for (; i < n; i++){
		p = GetPonto();
		if (i > 0) printf("%0.2f\n", Distance(p, lastP));
		else printf("-\n");
		lastP = p;
	}



	return 0;
}

tPonto Ponto(int x, int y){
	tPonto p = {x, y};
	return p;
}

tPonto GetPonto(){
	tPonto p;
	scanf("%d %d", &p.x, &p.y);
	return p;
}

void PrintPonto(tPonto p){
	printf("(%d,%d)", p.x, p.y);
}

float Distance(tPonto p, tPonto q){
	int x = p.x - q.x;
	int y = p.y - q.y;
	int h = x*x + y*y;
	return sqrt(h);
}