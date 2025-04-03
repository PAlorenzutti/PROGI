#include<stdio.h>
#include<math.h>

int algarismo(int numero){

    int a, b, c, d, dezena;

    //número de exemplo: 654321 

    //primeiro numero = centenas de milhar (6)
    a = numero/100000;

    //segundo numero = dezenas de milhar (5)
    b = (numero - (100000 * a))/10000;

    //terceiro numero = unidades de milhar (4)
    c = (numero - (100000 * a) - (10000 * b))/1000;

    //quarto numero = centenas (3)
    d = (numero - (100000 * a) - (10000 * b) - (1000 * c))/100;

    //quinto numero = dezenas (2)
    dezena = (numero - (100000 * a) - (10000 * b) - (1000 * c) - (100 * d))/10;

    return dezena;

}

int main(){

    int numero1, numero2, numero3, menor;
    scanf("%d%d%d", &numero1, &numero2, &numero3);

    numero1 = fabs(algarismo(numero1));
    numero2 = fabs(algarismo(numero2));
    numero3 = fabs(algarismo(numero3));

    //inicialmente, assume que o menor é numero1
    menor = numero1;

    //verifica se numero2 é menor do que o valor atual de menor e não é zero
    if(numero2 < menor && numero2 != 0){
        menor = numero2;
    }

    //verifica se numero3 é menor do que o valor atual de menor e não é zero
    if(numero3 < menor && numero3 != 0){
        menor = numero3;
    }

    //Verificando se todos os números são iguais a 0
    if(menor == 0){
        printf("Nenhum");
    }else if (menor == numero1){
        printf("N1");
    }else if(menor == numero2){
        printf("N2");
    }else{
        printf("N3");
    }

    return 0;

}