#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} tPonto;

typedef struct {
	tPonto i;
	tPonto f;
} tReta;

tReta Reta(tPonto i, tPonto f);
tReta GetReta();
void PrintReta(tReta r);
tPonto GetInicio(tReta r);
tPonto GetFim(tReta r);
tReta Move(tReta r, int delta);
float Length(tReta r);

tPonto GetPonto();
int Quadrant(tPonto p);

int main()
{
	int n;
	scanf("%d", &n);

	int i = 0;
	tReta r;
	for (; i < n; i++){
		r = GetReta();
		if (Quadrant(r.i) != Quadrant(r.f) || Quadrant(r.i) == 0 || Quadrant(r.f) == 0)
			printf("DIFERENTE\n");
		else printf("MESMO\n");
	}

	return 0;
}

tPonto GetPonto(){
	tPonto p;
	scanf("%d %d", &p.x, &p.y);
	return p;
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

tReta Reta(tPonto i, tPonto f){
	tReta r = { i, f };
	return r;
}

tReta GetReta(){
	tPonto i, q;
	scanf("%*c");
	i = GetPonto();
	scanf("%*c");
	q = GetPonto();
	return Reta(i, q);
}