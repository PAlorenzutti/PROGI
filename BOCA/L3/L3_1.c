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
    float num1, num2; 
  
    //driblar o erro de run time
    while(scanf("%f %f", &num1, &num2) > 0){ 
        printf("%.2f", soma(num1, num2)); 

        printf(" %.2f", subtracao(num1, num2)); 

        printf(" %.2f", divisao(num1, num2)); 

        printf(" %.2f\n", multi(num1, num2)); 
    } 
  
    return 0;     
}