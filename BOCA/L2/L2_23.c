#include <stdio.h>

void contagem(char entrada[], int vetores[]){
    int i = 0;
    int j = 0;

    while(entrada[i]){
        if(entrada[i] == '(' && entrada[i - 1] != '('){
            vetores[j] = i;
            j++;
        }

        if(entrada[i] == ')' && entrada[i + 1] != ')'){
            vetores[j] = i;
            j++;
        }

        i++;
    }
}

int main(){
    char entrada[100];
    int vetores[100];
    int i, j;

    scanf("%s", entrada);

    contagem(entrada, vetores);

    i = 0;
    j = 0;

    printf("RESP:");

    while(entrada[i]){
        if(i == vetores[j]){
            i++;
            while(i < vetores[j + 1]){
                printf("%c", entrada[i]);
                i++;
            }
            j += 2;
        }

        if(entrada[i] == '.'){
            entrada[i + 1] = '\0';
        }

        i++;
    }

    return 0;
}