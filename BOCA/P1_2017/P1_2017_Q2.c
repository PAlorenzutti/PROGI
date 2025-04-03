#include <stdio.h>

int main(){
    int pessoa1, pessoa2;

    scanf("%d %d", &pessoa1, &pessoa2);

    if(pessoa1 <= 10 && pessoa1 >= 1 && pessoa2 <= 10 && pessoa2 >= 1){
        if(pessoa1 <= 5 && pessoa2 <= 5){
            if(pessoa1 == pessoa2){
                printf("Um homem");
            }else{
                printf("Par de homens");
            }
        }else if(pessoa1 > 5 && pessoa2 > 5){
            if(pessoa1 == pessoa2){
                printf("Uma mulher");
            }else{
                printf("Par de mulheres");
            }
        }else{
            printf("Um casal");
        }
    }else{
        printf("Invalido");
    }

    return 0;
}