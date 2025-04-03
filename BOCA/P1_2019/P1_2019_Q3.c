#include <stdio.h>
#include <ctype.h>

int ehLetra(char letra){
    letra = toupper(letra);

    if(letra > 64 && letra < 91){
        return 1;
    }else{
        return 0;
    }
}

int ehNumero(char letra){
    if(letra > 47 && letra < 57){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char letra;
    int i = 0, j = 0, k = 0;
    
    scanf("%c", &letra);

    while(i < 8){
        if(ehLetra(letra) == 0 && i < 3){
            j++;
        }

        if(ehNumero(letra) == 0 && i > 3){
            k++;
        }
        
        scanf("%c", &letra);
        i++;
    }

    if(j == 0 && k == 0){
        printf("Codigo valido!");
    }else if(j > 0 && k == 0){
        printf("Codigo invalido!Problema nas letras!");
    }else if(j == 0 && k > 0){
        printf("Codigo invalido!Problema nos numeros!");
    }else{
        printf("Codigo invalido!Problema nas letras e nos numeros!");
    }

    return 0;
}