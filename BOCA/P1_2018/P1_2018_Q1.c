#include <stdio.h>

int main(){
    int x1, y1, x2, y2, aux;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if(x2 < x1){
        aux = x2;
        x2 = x1;
        x1 = aux;

        aux = y2;
        y2 = y1;
        y1 = aux;
    }

    if(y1 > y2){
        printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x1, y1, x1, y2, x2, y2, x2, y1);
    }else{
        printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x1, y2, x1, y1, x2, y1, x2, y2);
    }
    
    return 0;
}