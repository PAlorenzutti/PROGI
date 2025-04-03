#include <stdio.h>
#include <string.h>

int main(){
    char texto1[100];
    char texto2[100];

    gets(texto1);

    strcpy(texto2, texto1);

    printf("%s", texto2);

    return 0;
}