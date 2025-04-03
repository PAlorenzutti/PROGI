#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 80

int main(){
    FILE *fr;
    FILE *fw;

    char linha[MAX];

    if(!(fr = fopen("meuarquivo.txt", "r"))){
        printf("Erro ao abrir arquivo de leitura.");
        exit(1);
    }

    if(!(fw = fopen("copia.txt", "w"))){
        printf("Erro ao abrir arquivo de cópia.");
    }

    while(!(feof(fr))){
        fgets(linha, MAX, fr);
        fprintf(fw, "%s", linha);
    }

    fclose(fr);
    fclose(fw);

    return 0;
}