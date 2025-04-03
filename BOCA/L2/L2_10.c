#include <stdio.h>

void tabuada(int i)
{
    int j;

    for(j = 1; j <= 10; j++){
        printf("%d x %d = %d\n", i, j, i*j);
    }
}

int main()
{
    int n, m, i;
    scanf("%d%d", &n, &m);

    for(i = n; i <= m; i++){
        tabuada(i);
    }

    return 0;
}