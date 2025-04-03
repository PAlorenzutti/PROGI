#include <stdio.h>
#include <string.h>

int inverso(char string1[]){
    int i, j;

    i = strlen(string1);

    char string2[i];

    j = 0;
    i--;

    while(j <= i){
        string2[j] = string1[i - j];
        j++;
    }

    string2[j] = '\0';

    strcpy(string1, string2);

    return 0;
}

int main(){
    char texto[100];

    gets(texto);

    inverso(texto);

    printf("%s", texto);
}