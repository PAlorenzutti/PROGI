#include <stdio.h>

int main(){
    int codificacao, numero, avanco, retrocesso;
    char caractere;

    scanf("%d %d", &codificacao, &numero);

    while(caractere != '.'){
        scanf("%c", &caractere);

        if(codificacao == 1){
            avanco = caractere + (numero%26);

            if((caractere > 96) && (caractere < 123)){
                if(avanco >= 123){
                    caractere = avanco - 26; 
                }else{
                    caractere = avanco;
                }
            }
        }else if(codificacao == 2){
            retrocesso = caractere - (numero%26);

            if(caractere > 96 && caractere < 123){
                if(retrocesso <= 96){
                    caractere = retrocesso + 26;
                }else{
                    caractere = retrocesso;
                }
            }
        }else{
            printf("Operacao invalida.");
            return 0;
        }

        printf("%c", caractere);
    }

    return 0;
}