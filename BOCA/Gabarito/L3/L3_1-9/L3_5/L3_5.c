#include <stdio.h>

int Propriedade(int num);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    a++;
    while(a < b){
        if (Propriedade(a) == 1) printf("%d\n", a);
        a++;
    }

    return 0;
}

int Propriedade(int num){ 
    int halfLeft = num / 100;
    int halfRight = num - halfLeft * 100;
    int r = halfLeft + halfRight;
    return (r * r == num) ? 1 : 0;
}