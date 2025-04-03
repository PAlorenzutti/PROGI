#include<stdio.h>
#include<math.h>

double s1(int i){

    double termo;

    termo = (double)(2 * i - 1)/(i);

    return termo;

}

double s2(int i){

    double termo;

    termo = (double)pow(2, i)/(51 - i);

    printf("2 ^ %d / (%d) = %.2lf\n", i, 51 - i, termo);

    return termo;

}

double s3(int i){

    double termo;

    termo = (double)i/pow(i, 2);

    return termo;

}

int main(){

    int opcao, j;
    double soma = 0;
    scanf("%d", &opcao);

    if(opcao == 1){

        for(j = 1; j <= 50; j++){
            soma = soma + s1(j);
        }

        printf("%.6lf", soma);

    }

    if(opcao == 2){
        double termo;

        for(j = 1; j <= 50; j++){
            termo = (double)pow(2, j)/(51 - j);
            soma += termo;
        }

        printf("%.6lf", soma);

    }

    if(opcao == 3){

        for(j = 1; j <= 10; j++){
            soma = soma + s3(j);
        }

        printf("%.6lf", soma);

    }

    return 0;

}