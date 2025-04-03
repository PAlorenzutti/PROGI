#include <stdio.h>
#include <locale.h>
#define MAX 100

int contaCaracter(char c, char s[MAX]){
    int contador, i;

    contador = 0;
    i = 0;

    while(s[i] != '\0'){
        if(s[i] == c){
            contador++;
        }

        i++;
    }

    return contador;
}

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    char c;
    char s[MAX];
    int i, contador;

    printf("\nDigite o caracter que deseja medir: ");
    scanf("%c", &c);

    printf("\nDigite a string que deseja avaliar: ");
    scanf("%s", s);

    contador = contaCaracter(c, s);

    printf("\nO caracter '%c' aparece %dx\n", c, contador);

    return 0;
}