#include <stdio.h>
#include <math.h>

typedef struct{
	int x;
	int y;
} tPonto;

tPonto Ponto(int x, int y);
tPonto GetPonto();
void PrintPonto(tPonto p);
tPonto SetX(tPonto p, int x);
tPonto SetY(tPonto p, int y);
tPonto Move(tPonto p, tPonto delta);
float Distance(tPonto p, tPonto q);
int Quadrant(tPonto p);
tPonto Simetrico(tPonto p);

int main()
{
	int n;
	scanf("%d", &n);

	int i = 0;
	tPonto p;
	for (; i < n; i++){
		p = GetPonto();
		PrintPonto(p);
		printf(" %d ", Quadrant(p));
		PrintPonto(Simetrico(p));
		printf(" %d\n", Quadrant(Simetrico(p)));
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
tPonto SetX(tPonto p, int x){
	p.x = x;
	return p;
}
tPonto SetY(tPonto p, int y){
	p.y = y;
	return p;
}
tPonto Move(tPonto p, tPonto delta){
	p = SetX(p, delta.x);
	p = SetY(p, delta.y);
	return p;
}
float Distance(tPonto p, tPonto q){
	int x = p.x - q.x;
	int y = p.y - q.y;
	int h = x*x + y*y;
	return sqrt(h);
}
int Quadrant(tPonto p){
	if (p.x == 0 || p.y == 0) return 0;
	else if (p.x > 0) {
		if (p.y > 0) return 1;
		else return 4;
	}
	else if (p.x < 0){
		if (p.y > 0) return 2;
		else return 3;
	}
}
tPonto Simetrico(tPonto p){
	tPonto q = {-p.x, -p.y};
	return q;
}