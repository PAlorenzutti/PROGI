#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int lado1, lado2, lado3;
    scanf("%d%d%d", &lado1, &lado2, &lado3);

    if(lado1 < lado2 + lado3 || lado2 < lado1 + lado3 || lado3 < lado1 + lado2){
        if(lado1 == lado2 || lado2 == lado3 || lado1 == lado3){
            printf("O tri�ngulo � is�sceles.");
        }else if(lado1 == lado2 && lado2 == lado3){
            printf("O tri�ngulo � equil�tero.");
        }else{
            printf("O tri�ngulo � escaleno.");
        }
    }else{
        printf("Não forma um tri�ngulo.");
    }

    return 0;

}