#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int base, expoente, potencia, i;
    printf("Digite a base e o expoente, respectivamente:\n");
    scanf("%d %d", &base, &expoente);

    i = 1;
    potencia = base;

    if(expoente == 0){
        if(base == 0){
            printf("0 elevado a 0 � indetermina��o.");
        }else{
            printf("A potencia de %d elevado a 0 �: 1", base);
        }
    }else{
        while(i < expoente){
        potencia = potencia * base;
        i = i + 1;
        }
        printf("A pot�ncia de %d elevado a %d �: %d", base, expoente, potencia);
    }

    return 0;

}