#include <stdio.h> 
 
float soma(float num1, float num2){
    return num1 + num2;
}

float subtracao(float num1, float num2){
    return num1 - num2;
}

float divisao(float num1, float num2){
    return num1 / num2;
} 
float multi(float num1, float num2){
    return num1 * num2;
}
 
int main(){ 
    float resultado, numero;
    char operador; 
  
    scanf("%f", &resultado);

    while(scanf("%f %c", &numero, &operador) == 2){ 
        if(operador == '+'){
            resultado = soma(resultado, numero);
        }

        if(operador == '-'){
            resultado = subtracao(resultado, numero);
        }

        if(operador == '*'){
            resultado = multi(resultado, numero);
        }

        if(operador == '/'){
            resultado = divisao(resultado, numero);
        }
    }

    printf("%.2f", resultado);
  
    return 0;     
}