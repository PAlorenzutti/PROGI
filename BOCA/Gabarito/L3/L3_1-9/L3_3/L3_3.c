#include <stdio.h>

int EhPrimo(int num);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    a++;
    while(a < b){
        if (EhPrimo(a) > 0) printf("%d ", a); a++;
    }

    return 0;
}

int EhPrimo(int num){ 
    int i;
    for (i = 2; i < num; i++){
        if (num % i == 0) return 0;
    }
    return num;
}