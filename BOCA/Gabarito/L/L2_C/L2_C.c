#include <stdio.h>

int main(){
    int l, c, i, j, n, min = 32e5, max = 32e-5, diff, maxDiff = 32e-5, line = -1;
    scanf("%d %d", &l, &c);

    for (i = 1; i <= l; i++) {
        for (j = 1; j <= c; j++){
            scanf("%d", &n);
            if (n > max) max = n;
            if (n < min) min = n;
        }
        diff = (max - min > 0) ? max - min : (max - min) * -1;
        if (diff >= maxDiff) {
            line = i;
            maxDiff = diff;
        }
        min = 32e5;
        max = 32e-5;
    }

    printf("Linha %d tem a maior distancia %d", line, maxDiff);

    return 0;
}