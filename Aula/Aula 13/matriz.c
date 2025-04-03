#include <stdio.h>

#define MAX_LIN 100
#define MAX_COL 100

typedef int tipoInfo;

typedef struct{
    tipoInfo info[MAX_LIN][MAX_COL];
    int numeroLinhas, numeroColunas;
}tipoMatriz;

tipoInfo lerInfo(){
    tipoInfo info;
    scanf("%d", &info);
    return info;
}

tipoMatriz iniciarMatrizVazia(){
    tipoMatriz mat;

    mat.numeroLinhas = 0;
    mat.numeroColunas = 0;

    return mat;
}

tipoMatriz receberLinhasColunas(){
    tipoMatriz mat;

    scanf("%dx%d", &mat.numeroLinhas, &mat.numeroColunas);

    return mat;
}

tipoMatriz leituraMatriz(tipoMatriz mat){
    int i, j;

    mat = iniciarMatrizVazia();

    mat = receberLinhasColunas();

    for(i = 0; i < mat.numeroLinhas; i++){
        for(j = 0; j < mat.numeroColunas; j++){
            mat.info[i][j] = lerInfo();
        }
    }

    return mat;
}
void printarMatriz(tipoMatriz mat){
    int i, j;

    for(i = 0; i < mat.numeroLinhas; i++){
        for(j = 0; j < mat.numeroColunas; j++){
            printf("%d ", mat.info[i][j]);
        }

        printf("\n");
    }   
}

tipoInfo somaMatriz(tipoMatriz mat){
    tipoInfo soma = 0;

    int i, j;

    for(i = 0; i < mat.numeroLinhas; i++){
        for(j = 0; j < mat.numeroColunas; j++){
            soma += mat.info[i][j];
        }
    }

    return soma;
}

tipoInfo somaLinhaMatriz(tipoMatriz mat, int linha){
    int j;
    tipoInfo soma = 0;

    for(j = 0; j < mat.numeroColunas; j++){
        soma += mat.info[linha][j];
    }

    return soma;
}

tipoInfo somaColunaMatriz(tipoMatriz mat, int coluna){
    int i;
    tipoInfo soma = 0;

    for(i = 0; i < mat.numeroLinhas; i++){
        soma += mat.info[i][coluna];
    }

    return soma;
}

tipoInfo somaDiagonalPrincipal(tipoMatriz mat){
    tipoInfo soma;
    int limite, i;

    if(mat.numeroLinhas > mat.numeroColunas){
        limite = mat.numeroColunas;
    }else{
        limite = mat.numeroLinhas;
    }

    soma = 0;

    for(i = 0; i < limite; i++){
        soma += mat.info[i][i];
    }

    return soma;
}

tipoInfo somaDiagonalSecundaria(tipoMatriz mat){
    tipoInfo soma;
    int limite, i;

    if(mat.numeroLinhas > mat.numeroColunas){
        limite = mat.numeroColunas;
    }else{
        limite = mat.numeroLinhas;
    }

    soma = 0;

    for(i = 0; i < limite; i++){
        soma += mat.info[i][(limite - i) - 1];
    }

    return soma;
}

tipoInfo somaTriangularInferiorA(tipoMatriz mat){
    tipoInfo soma = 0;
    int i, j;

    for(i = 0; i < mat.numeroLinhas; i++){
        for(j = 0; j < mat.numeroColunas; j++){
            if(i > j){
                soma += mat.info[i][j];
            }else{
                break;
            }
        }
    }

    return soma;
}

tipoInfo somaTriangularSuperior(tipoMatriz mat){
    tipoInfo soma = 0;
    int i, j;

    for(i = 0; i < mat.numeroLinhas; i++){
        for(j = 0; j < mat.numeroColunas; j++){
            if(j > i){
                soma += mat.info[i][j];
            }
        }
    }

    return soma;
}

tipoInfo somaTriangularInferiorB(tipoMatriz mat){
    tipoInfo soma = 0;
    int i, j;

    for(j = 0; j < mat.numeroColunas; j++){
        for(i = j + 1; i < mat.numeroLinhas; i++){
            soma += mat.info[i][j];
        }
    }

    return soma;
}

tipoMatriz produtoEscalar(){
    tipoMatriz a, b, c;
    int i, j, k;

    a = iniciarMatrizVazia();
    b = iniciarMatrizVazia();
    c = iniciarMatrizVazia();

    a = leituraMatriz(a);
    b = leituraMatriz(b);

    c.numeroLinhas = a.numeroLinhas;
    c.numeroColunas = b.numeroColunas;

    for(i = 0; i < c.numeroLinhas; i++){
        for(j = 0; j < c.numeroColunas; j++){
            c.info[i][j] = 0;

            for(k = 0; k < a.numeroColunas; k++){
                c.info[i][j] += a.info[i][k] * b.info[k][j];
            }
        }
    }

    return c;
}

tipoMatriz fazerTransposta(tipoMatriz mat){
    tipoMatriz transposta;
    int i, j;

    for(i = 0; i < mat.numeroLinhas; i++){
        for(j = 0; j < mat.numeroColunas; j++){
            transposta.info[j][i] = mat.info[i][j];
        }
    }

    transposta.numeroLinhas = mat.numeroColunas;
    transposta.numeroColunas = mat.numeroLinhas;

    return transposta;
}

int quadradoMagico(tipoMatriz mat){
    int soma, i;

    soma = somaDiagonalPrincipal(mat);

    if(somaDiagonalSecundaria(mat) != soma){
        return 0;
    }

    for(i = 0; i < mat.numeroLinhas; i++){
        if(somaLinhaMatriz(mat, i) != soma){
            return 0;
        }

        if(somaColunaMatriz(mat, i) != soma){
            return 0;
        }
    }

}

int invalida (tipoMatriz mat, int i, int j) {
   return i < 0 || j < 0 || i >= mat.numeroLinhas || j >= mat.numeroColunas;
}

tipoInfo somaVizinhanca(tipoMatriz mat, int linha, int coluna){
   int i, j; 
   int soma;

   soma = -mat.info[linha][coluna];

   for(i = linha - 1; i < linha + 2; i++) {
      for(j = coluna - 1; j < coluna + 2; j++){
         if(!invalida(mat, i, j)){
            soma = soma + mat.info[i][j];
         }
      }
   }

   return soma;
}

void maiorVizinhanca(tipoMatriz mat){
   int i, j, linhaMaior, colunaMaior;
   int soma, maiorSoma;

   maiorSoma = somaVizinhanca(mat, 0, 0);

   linhaMaior = 0;
   colunaMaior = 0;

   for (i = 0; i < mat.numeroLinhas; i++){
      for (j = 0; j < mat.numeroColunas; j++) {
         soma = somaVizinhanca(mat, i, j);

         if(soma > maiorSoma){
            maiorSoma = soma;
            linhaMaior = i;
            colunaMaior = j;
         }
      }
   }

   printf ("Posicao (%d, %d) - soma de vizinhos = %d.\n", linhaMaior, colunaMaior, maiorSoma);
}

int main(){
    tipoMatriz mat;

    mat = leituraMatriz(mat);

    printf("%d", somaAcimaDiagonalSecundaria(mat));
k
    return 0;   
}