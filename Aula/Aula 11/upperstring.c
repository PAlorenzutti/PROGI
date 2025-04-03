#include <stdio.h>
#include <ctype.h>

int upperString(char string[]){
    int i = 0;

    while(string[i]){
        string[i] = toupper(string[i]);
        i++;
    }

    return 0;
}

int main(){
    char texto[100];

    gets(texto);

    upperString(texto);

    printf("%s", texto);
}