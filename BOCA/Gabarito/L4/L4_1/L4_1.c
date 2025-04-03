#include <stdio.h>

typedef struct {
	int cod;
	float price;
	int store;
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p);

int main(){
	int n, i = 1;
	scanf("%d", &n);

	tProduto p, pMax = {-1, -1.0, -1}, pMin = {32e5, 32e5, 32e5};
	for (; i <= n; i++){
		p = LeProduto();
		if (EhProduto1MaiorQ2(p, pMax)) pMax = p;
		if (EhProduto1MenorQ2(p, pMin)) pMin = p;
		if (!TemProdutoEmEstoque(p)){
			printf("FALTA:");
			ImprimeProduto(p);
		}
	}

	printf("MAIOR:");
	ImprimeProduto(pMax);
	printf("MENOR:");
	ImprimeProduto(pMin);

	return 0;
}

tProduto LeProduto(){
	tProduto p;
	scanf("%d;%f;%d", &p.cod, &p.price, &p.store);
	return p;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
	return p1.price > p2.price; 
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2){
	return p1.price < p2.price;
}

int TemProdutoEmEstoque(tProduto p){
	return p.store > 0;
}

void ImprimeProduto(tProduto p){
	printf("COD %d, PRE %0.2f, QTD %d\n", p.cod, p.price, p.store);
}