#include <stdio.h>

int algarismos(int numero)
{
    int a, b, c, d; 
    int ab, cd, ef;

    //segundo algarismo = unidades de milhar (4)
    a = numero/1000;

    //terceiro algarismo = centenas (3)
    b = (numero-(1000*a))/100;

    //quarto algarismo = dezenas (2)
    c = (numero-(1000*a)-(100*b))/10;

    //quinto algarismo = unidades (1)
    d = (numero-(1000*a)-(100*b)-(10*c));

    ab = a * 10 + b;
    cd = c * 10 + d;
    ef = ab + cd;

    if((ef * ef) == numero){
        return 1;
    }else{
        return 0;
    }
    
}

int main()
{
    int n, m, aux;
    scanf("%d %d", &n, &m);

    if(n > m){
        aux = m;
        m = n;
        n = aux;
    }

    if(n < 1000 || m > 9999){
        return 0;
    }

    while(n < m){
        n++;

        if(n == m){
            break;
        }

        if(algarismos(n)){
            printf("%d\n", n);
        }
    }

    return 0;
}