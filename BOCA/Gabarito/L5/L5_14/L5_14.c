#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int codigo;
	char sobrenome[21];
	char nome[21];
	int nota;
	int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
int ComparaString(char * str1, char * str2);
int hasUsed(int vec[], int index, int qtd);

int main(){
	int qtdCand, i = 0;
	scanf("%d", &qtdCand);

	tCandidato candidatos[qtdCand];
	for (i = 0; i < qtdCand; i++) candidatos[i] = LeCandidato();

	int used[qtdCand], u = 0;
	for (i = 0; i < qtdCand; i++) used[i] = -1;

	int j = 0, test = 0;
	for (i = 0; i < qtdCand; i++){
		if (!hasUsed(used, i, qtdCand)){
			for (j = i + 1; j < qtdCand; j++){
				if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome)){
					if (!test) { ImprimeCandidato(candidatos[i]); test = !test; }
					ImprimeCandidato(candidatos[j]);
					used[u] = j;
					u++;
				}
			}
			test = 0;
		}
	}
	
	return 0;
}

tCandidato LeCandidato(){
	tCandidato candidato;
	scanf("%*[^{]");
	scanf("%*[{ ]");
	scanf("%d", &candidato.codigo);
	scanf("%*[, ]");
	scanf("%[^,],", candidato.sobrenome);
	scanf("%*[ ]");
	scanf("%[^,],", candidato.nome);
	scanf("%d", &candidato.nota);
	scanf("%*[, ]");
	scanf("%d", &candidato.idade);
	scanf("%*[^\n]\n");
	return candidato;
}

void ImprimeCandidato(tCandidato candidato){
	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
	candidato.codigo, candidato.nome,
	candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char * str1, char * str2){
	int i;
	for (i = 0; str1[i] && str2[i]; i++){
		if (str1[i] == str2[i]);
		else return 0;
	}
	return str1[i] == str2[i];
}

int hasUsed(int vec[], int index, int qtd){
	int i = 0;
	for (i = 0; i < qtd; i++)
		if (vec[i] == index) 
			return 1;
	return 0;
}