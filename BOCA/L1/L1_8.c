#include<stdio.h>

int main(){

    char letra;

    scanf("%c", &letra);

    if(letra == 'A' || letra == 'B' || letra == 'C' || letra == 'D' || letra == 'E'){
        printf("Vogal");
    }else if(letra == 'a' || letra == 'b' || letra == 'c' || letra == 'd' || letra == 'e'){
        printf("Vogal");
    }else{
        printf("Nao vogal");
    }
}