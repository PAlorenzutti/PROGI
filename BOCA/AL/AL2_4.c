#include <stdio.h>

int main() {
    int numero, palindromo = 0, original, resto;

    scanf("%d", &numero);

    original = numero;

    while(numero > 0){
        resto = numero % 10;
        palindromo = palindromo * 10 + resto;
        numero = numero / 10;
    }

    if(original == palindromo){
        printf("SIM");
    }else{
        printf("NAO");
    }

    return 0;
}