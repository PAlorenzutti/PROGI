#include <stdio.h>

void ConcatenaString(char nome[], char sobrenome[], char nomeCompleto[]){
    int i;

    for(i = 0; nome[i]; i++){
        nomeCompleto[i] = nome[i];
    }

    int j;

    for(j = 0; sobrenome[j]; i++, j++){
        nomeCompleto[i] = sobrenome[j];
    }

    nomeCompleto[i] = '\0';
}


int main(){ 
    char nome[1000]; 
    char sobrenome[1000]; 
    char nomeCompleto[2000]; 
   
    while (scanf("%s", sobrenome) == 1 && scanf("%s", nome) == 1){ 
        ConcatenaString(nome, sobrenome, nomeCompleto); 

        printf("%s\n", nomeCompleto); 
    } 

    return 0;     
}