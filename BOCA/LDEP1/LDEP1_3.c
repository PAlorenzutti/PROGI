#include<stdio.h>

int main(){

    int n;
    int i = 1;

    scanf("%d", &n);

    while(i < n){
        if(i % 2 == 0){
            printf("%d ", i);
        }else if(i % 3 == 0){
            printf("%d ", i);
        }
        i++;
    }

    return 0;

}