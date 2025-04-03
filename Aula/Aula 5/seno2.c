#include<stdio.h>
#include<math.h>
#include<locale.h>
#define pi 3.141592

int main(){

    setlocale(LC_ALL, "portuguese_brazil");

    float x, y, termo, seno;
    int i, j, impar, fatorial = 1;

    printf("Digite o �ngulo, em graus, do qual se deseja obter o seno: ");
    scanf("%f", &x);

    //convers�o graus para radianos
    y = (x * pi)/180;
    termo = y;

    for(i = 0; fabs(termo) > 0.001; i++){

        //expoente impar
        impar = 1 + 2*i;

        //fatorial  
        for(j = 1; j <= impar; j++){
            fatorial = fatorial * j;
        }

        //termo e reinicializa��o
        termo = pow(-1, i)*pow(y, impar)/fatorial;
        fatorial = 1;

        //soma
        seno = seno + termo;

    }

    printf("O valor do seno de %.2f� � %.4f", x, seno);
    return 0;

}