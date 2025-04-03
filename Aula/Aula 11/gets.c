#include <stdio.h>

int main(){
    char texto[100];

    gets(texto);

    printf("%s\n", texto);

    return 0;
}