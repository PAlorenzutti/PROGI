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

tPonto Ponto(int x, int y);
tPonto GetPonto();
float Distance(tPonto p, tPonto q);

int main()
{
	int n;
	scanf("%d", &n);

	int i = 0;
	tPonto p;
	tReta r;
	float di = 0, df = 0;
	for (; i < n; i++){
		p = GetPonto();
		r = GetReta();

		di = Distance(r.i, p);
		df = Distance(r.f, p);

		if (di > df) printf("FIM");
		else if (di < df) printf("INICIO");
		else printf("EQUIDISTANTE");
		printf("\n");
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

float Distance(tPonto p, tPonto q){
	int x = p.x - q.x;
	int y = p.y - q.y;
	int h = x*x + y*y;
	return sqrt(h);
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

void PrintReta(tReta r){
	printf("[(%d,%d):(%d:%d)]", r.i.x, r.i.y, r.f.x, r.f.y);
}

tPonto GetInicio(tReta r){ return r.i; }
tPonto GetFim(tReta r){ return r.f; }

tReta Move(tReta r, int delta){
	tPonto i = { r.i.x + delta, r.i.y + delta },
			f = { r.f.x + delta, r.f.y + delta };
	return Reta(i, f);
}

float Length(tReta r){
	return Distance(r.i, r.f);
}