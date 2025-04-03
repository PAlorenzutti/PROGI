#include <stdio.h>

int resultado;

int soma(int n1, int n2){
    resultado = n1 + n2;

    return resultado;
}

int subtracao(int n1, int n2){
    resultado = n1 - n2;

    return resultado;
}

int multi(int n1, int n2){
    resultado = n1 * n2;

    return resultado;
}

int divisao(int n1, int n2){
    resultado = n1/n2;

    return resultado;
}

int main(){
    int numero1, numero2;
    char simbolo;

    scanf("%d %d %c", &numero1, &numero2, &simbolo);

    if(simbolo == '+'){
        printf("RESP:%d", soma(numero1, numero2));
    }else if(simbolo == '-'){
        printf("RESP:%d", subtracao(numero1, numero2));
    }else if(simbolo == '*'){
        printf("RESP:%d", multi(numero1, numero2));
    }else if(simbolo == '/'){
        printf("RESP:%d", divisao(numero1, numero2));
    }else{
        printf("Invalido");
    }

    return 0;

}