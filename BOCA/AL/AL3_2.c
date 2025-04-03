#include<stdio.h>

int main(){

    int quantidade, resto, i, j = 0, primo, divisor;

    scanf("%d", &quantidade);

    for(primo = 2; j < quantidade; primo++){
        divisor = 0;
        for(i = 1; i <= primo; i++){
            resto = primo % i;
            if(resto == 0){
                divisor++;
            }
        }
        if(divisor == 2){
            printf("%d ", primo);
            j++;
        }
    }

    return 0;

}