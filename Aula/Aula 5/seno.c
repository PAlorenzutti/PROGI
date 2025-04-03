#include<stdio.h>
#include<math.h>
#include<locale.h>
#define pi 3.14

int main(){

    setlocale(LC_ALL, "portuguese_brazil");

    float x, y, seno, termo;
    int n, impar;

    printf("Digite o �ngulo, em graus, do qual se deseja obter o seno: ");
    scanf("%f", &x);

    //convers�o graus para radianos
    y = (x * pi)/180;
    termo = y;

    for(n = 1; fabs(termo) > 0.001; n++){
        
        //s�rie
        seno = seno + termo;

        //expoente impar
        impar = 1 + 2*n;

        //termo
        termo = ((-1) * termo * pow(y, 2))/(impar * (impar - 1));

    }

    printf("O valor do seno de %.2f� � %.4f", x, seno);
    return 0;

}