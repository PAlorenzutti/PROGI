#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero;

    FILE *fwb;

    if(!(fwb = fopen("numeros.bin", "wb"))){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    scanf("%d", &numero);

    while(numero >= 0){
        fwrite(&numero, sizeof(int), 1, fwb);
        scanf("%d", &numero);
    }

    fclose(fwb);
    
    return 0;
}