#include <stdio.h>

int dezena(int numero1, int numero2, int numero3){
    int centenas, dezenas, numero;
    
    numero = numero1 + numero2 + numero3;

    centenas = numero/100;

    dezenas = (numero - (100 * centenas))/10;

    return dezenas;
}

int main(){
    int hora1, minuto1, segundo1;
    int hora2, minuto2, segundo2;

    scanf("%d %d %d", &hora1, &minuto1, &segundo1);
    scanf("%d %d %d", &hora2, &minuto2, &segundo2);

    if(hora1 == hora2){
        if(minuto1 > minuto2){
            printf("RESP:%d", dezena(hora1, minuto1, segundo1));
        }else if(minuto2 > minuto1){
            printf("RESP:%d", dezena(hora2, minuto2, segundo2));           
        }else{
            if(segundo1 > segundo2){
                printf("RESP:%d", dezena(hora1, minuto1, segundo1));                
            }else if(segundo2 > segundo1){
                printf("RESP:%d", dezena(hora2, minuto2, segundo2)); 
            }else{
                printf("IGUAIS");
            }
        }
    }else if(hora1 > hora2){
        printf("RESP:%d", dezena(hora1, minuto1, segundo1));      
    }else{
        printf("RESP:%d", dezena(hora2, minuto2, segundo2));         
    }

    return 0;
}