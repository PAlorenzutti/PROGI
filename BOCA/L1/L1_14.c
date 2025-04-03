#include<stdio.h>

int main(){

    int x1, y1, x2, y2, x, y;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);

    if(x >= x1 && x <= x2 || x <= x1 && x >= x2){
        if(y >= y1 && y <= y2 || y <= y1 && y >= y2){
            printf("Dentro");
        }else{
            printf("Fora");
        }
    }else{
        printf("Fora");
    }

    return 0;

}