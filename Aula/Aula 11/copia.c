#include <stdio.h>

int copia(char destino[], char origem[]){
    int i = 0;

    while(origem[i]){
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';

    return 0;
}

int main(){
    char texto1[100];
    char texto2[100];

    gets(texto1);

    copia(texto2, texto1);

    printf("%s", texto2);

    return 0;
}