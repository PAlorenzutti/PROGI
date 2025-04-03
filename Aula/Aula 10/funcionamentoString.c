#include <stdio.h>
#define MAX 100

void lerFrase(char frase[]){
    int i = 0;

    scanf("%c", &frase[i]);

    while(frase[i] != '.'){
        i++;

        scanf("%c", &frase[i]);
    }

    frase[i + 1] = '\0';
}

int main(){
    char f[MAX];
    
    lerFrase(f);

    printf("%s\n", f);
}