#include <stdio.h>

int verificaPrimo(int n);
int transformaPrimo(int n);
int verificaNegativo(int n);

int main(){
    int l, c, i, j, n;
    scanf("%d %d", &l, &c);

    for (i = 0; i < l; i++){
        printf("\t");
        for (j = 0; j < c; j++){
            scanf("%d", &n);
            printf("%d ", transformaPrimo(n));
        }
        printf("\n");
    }

    return 0;
}

int verificaPrimo(int n){
    int i = 2;
    for (; i < n; i++) if (n%i == 0) return 0;
    return n != 1 && n != 0;
}

int transformaPrimo(int n){
    int i;
    if (verificaNegativo(n) == 1) {
        for (i = -n; i < 32000; i++) if (verificaPrimo(i) == 1) return -i;
    }
    else {
        for (i =  n; i < 32000; i++) if (verificaPrimo(i) == 1) return  i; 
    }
    return n;
}

int verificaNegativo(int n){
    return !(n >= 0);
}