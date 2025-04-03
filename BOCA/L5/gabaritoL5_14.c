#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int comparaString(char str1[], char str2[]){
    int i;
    i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] < str2[i]){
            return -1;
        }
        if (str1[i] > str2[i]){
            return +1;
        }
        i++;
    }
	if (str1[i] == str2[i]) {
			return 0;
	}else{
    	if (str1[i] < str2[i]){
            return -1;
		}else{
		 	return +1;
		}
	}
}

typedef struct{
	int codigo;
	char sobrenome[21];
	char nome[21];
	int nota;
	int idade;
} tInfo;

tInfo leInfo(){
	tInfo candidato;
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

void apresentaInfo(tInfo candidato){
	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", 
			candidato.codigo, candidato.nome, 
			candidato.sobrenome, candidato.nota, candidato.idade);
}

int comparaInfo (tInfo cand1, tInfo cand2) {
    return !comparaString(cand1.sobrenome, cand2.sobrenome);
}

typedef struct {
	tInfo info [MAX];
	int imprimiu [MAX];
	int n;
} tListaCand;

tListaCand leListaCand(int qtd) {
	int i;
	tListaCand cands;
	for(i = 0; i < qtd; i++){
		cands.info[i] = leInfo();
		cands.imprimiu[i] = 0;
	}
	cands.n = qtd;
	return cands;
}

void apresentaListaCand(tListaCand cands){
	int i, j;
	for(i = 0; i < cands.n; i++){
		for(j = i+1; j < cands.n; j++){
			if ( comparaInfo(cands.info[i], cands.info[j]) ){
				if ( !cands.imprimiu[i] ){
					cands.imprimiu[i] = 1;
					apresentaInfo(cands.info[i]);
				}
				if ( !cands.imprimiu[j] ){
					cands.imprimiu[j] = 1;
					apresentaInfo(cands.info[j]);
				}
			}
		}
	}
}


int main(){
	int qtdCand;
	tListaCand candidatos;
	
	scanf("%d", &qtdCand);
	candidatos = leListaCand(qtdCand);
	apresentaListaCand(candidatos);
	
    return 0;    
}