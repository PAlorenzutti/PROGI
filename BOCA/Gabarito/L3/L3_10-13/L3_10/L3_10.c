#include <stdio.h>

char Codifica(char letra, int n);
char Decodifica(char letra, int n);

int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);

int main(){
    int f, key;
    scanf("%d %d ", &f, &key);

    char c;
    if (f != 1 && f != 2) printf("Operacao invalida.");
    else {
        while(scanf("%c", &c) == 1){
            if (EhLetra(c)) {
                if (f == 1) printf("%c", Codifica(c, key));
                else if (f == 2) printf("%c", Decodifica(c, key));
            }
            else printf("%c", c);
            if (c == '.') break;
        }
    }
    return 0;
}

char Codifica(char letra, int n){
    char r = letra;
    if (EhLetraMaiuscula(letra)) {
        if (EhLetraMaiuscula(r + ((n*2)%26)) == 0)
            r += ((n*2)%26) - 26;
        else r += ((n*2)%26);
    }
    else {
        if (EhLetraMinuscula(r + (n%26)) == 0) 
            r += (n%26) - 26;
        else r += (n%26);
    }
    return r;
}

char Decodifica(char letra, int n){
    char r = letra;
    if (EhLetraMaiuscula(letra)) {
        if (EhLetraMaiuscula(r - ((n*2)%26)) == 0)
            r += 26 - ((n*2)%26);
        else r -= ((n*2)%26);
    }
    else {
        if (EhLetraMinuscula(r - n%26) == 0) 
            r += 26 - (n%26);
        else r -= (n%26);
    }
    return r;
}

int EhLetra(char c){
    return (EhLetraMaiuscula(c) || EhLetraMinuscula(c));
}

int EhLetraMaiuscula(char c){
    return (c >= 'A' && c <= 'Z');
}

int EhLetraMinuscula(char c){
    return (c >= 'a' && c <= 'z'); 
}