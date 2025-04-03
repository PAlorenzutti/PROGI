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
void OrdenarCandidatos(tCandidato *lista, int n);

int main(){
	int qtdCand, i = 0;
	scanf("%d", &qtdCand);

	tCandidato candidatos[qtdCand];
	for (i = 0; i < qtdCand; i++) candidatos[i] = LeCandidato();

	OrdenarCandidatos(candidatos, qtdCand);
	for (i = 0; i < qtdCand; ImprimeCandidato(candidatos[i]), i++);
	
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
		if (str1[i] < str2[i]) return -1;
		else if (str1[i] == str2[i]);
		else return 1;
	}
	return (str1[i] == str2[i]) ? 0 : (str1[i] == '\0') ? -1 : 1;
}

void OrdenarCandidatos(tCandidato *lista, int n){
	int i = 0, j = 0;
	tCandidato r;
	for (i = 0; i < n; i++){
		for (j = i+1; j < n; j++){
			if (ComparaString(lista[i].nome, lista[j].nome) == 1 || (ComparaString(lista[i].nome, lista[j].nome) == 0 && ComparaString(lista[i].sobrenome, lista[j].sobrenome) == 1)){
				r = lista[i];
				lista[i] = lista[j];
				lista[j] = r;
			}
		}
	}
}