#include<stdio.h>

int main(){

    int numero, casa, a, b, c, d, e;
    scanf("%d%d", &numero, &casa);

    //número de exemplo: 54321

    //primeiro algarismo = dezenas de milhar (5)
    a = numero/10000; 

    //segundo algarismo = unidades de milhar (4)
    b = (numero-(10000*a))/1000;

    //terceiro algarismo = centenas (3)
    c = (numero-(10000*a)-(1000*b))/100;

    //quarto algarismo = dezenas (2)
    d = (numero-(10000*a)-(1000*b)-(100*c))/10;

    //quinto algarismo = unidades (1)
    e = (numero-(10000*a)-(1000*b)-(100*c)-(10*d));

    if(casa == 1){
        if(e%2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }else if(casa == 2){
        if(d%2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }else if(casa == 3){
        if(c%2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }else if(casa == 4){
        if(b%2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }else if(casa == 5){
        if(a%2 == 0){
            printf("PAR");
        }else{
            printf("IMPAR");
        }
    }

    return 0;

}