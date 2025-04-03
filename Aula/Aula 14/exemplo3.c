#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int numero;

    FILE *frb;
    FILE *fw;

    if(!(frb = fopen("numeros.bin", "rb"))){
        printf("Erro ao abrir arquivo binário.");
        exit(1);
    }

    if(!(fw = fopen("numeros.txt", "w"))){
        printf("Erro ao abrir arquivo texto.");
        exit(1);
    }

    while((fread(&numero, sizeof(int), 1, frb))){
        fprintf(fw, "%d\n", numero);
    }

    fclose(frb);  
    fclose(fw);

    return 0;
}