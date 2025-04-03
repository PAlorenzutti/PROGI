#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, i, t, menor;
    i = 0;
    menor = 99999;

    printf("Digite o número de termos a serem digitados:\n");
    scanf("%d", &n);

    if(n > 0){
        while(i < n){
            printf("Digite o termo: ");
            scanf("%d", &t);

            if(t < menor){
                menor = t;
            }

            i = i + 1;
        }
        printf("\nO menor termo da sequência digitada é: %d\n", menor);        
    }else{
        printf("Sequência vazia.\n");
    }

    return 0;

}