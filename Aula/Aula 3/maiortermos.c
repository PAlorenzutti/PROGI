#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, i, t, maior;
    i = 0;
    maior = -1;

    printf("Digite o número de termos a serem digitados:\n");
    scanf("%d", &n);

    if(n > 0){
        while(i < n){
            printf("Digite o termo: ");
            scanf("%d", &t);

            if(t > maior){
                maior = t;
            }

            i = i + 1;
        }
        printf("O maior termo da sequência digitada é: %d", maior);
    }else{
        printf("Sequência vazia.\n");
    }

    return 0;

}