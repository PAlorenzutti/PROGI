#include <stdio.h>

int main(){
    int numero, menor, sequencia1 = 0, sequencia2 = 0, primeira = 0, ultima = 0, igual = 0;
    char caractere;

    while(scanf("%d", &numero)){
        if(sequencia1 == 0){
            menor = numero;
            sequencia1++;
        }

        if(numero < menor){
            menor = numero;
        }
    }

    if(scanf("%c", &caractere)){
        sequencia2 = 0;
    }

    while(scanf("%d", &numero)){
        if(numero == menor){
            if(sequencia2 == 0){
                primeira = sequencia2;
                igual++;
            }

            if(sequencia2 > 0 && igual == 0){
                primeira = sequencia2;
                igual++;
            }

            if(sequencia2 > primeira){
                ultima = sequencia2;
                igual++;
            }
        }

        sequencia2++;
    }

    if(primeira == 0 && ultima == 0){
        primeira = ultima = sequencia2;
    }

    if(igual == 1){
        ultima = primeira;
    }

    printf("%d %d %d", menor, primeira, ultima);

    return 0;
}