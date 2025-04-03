#include <stdio.h>

int main(){
    int linha, coluna, valor, i, j, maiorLinha, maiorColuna, maiorValor = -99999;

    scanf("%d %d", &linha, &coluna);

    for(i = 1; i <= linha; i++){
        for(j = 1; j <= coluna; j++){
            scanf("%d", &valor);

            if(valor > maiorValor){
                maiorValor = valor;
                maiorColuna = j;
                maiorLinha = i;
            }
        }
    }

    printf("%d (%d, %d)", maiorValor, maiorLinha, maiorColuna);

    return 0;
}