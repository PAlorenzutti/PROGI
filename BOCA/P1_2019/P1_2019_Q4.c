#include <stdio.h>
#include <locale.h>

int igual(int digito[]){
    int i = 0, j = 0;

    while(i < 10){
        if(digito[i] == digito[i + 1]){
            j++;
        }

        i++;
    }

    if(j == 10){
        return 1;
    }else{
        return 0;
    }
}

int digitoDez(int digito[]){
    int soma = 0, i = 0, decimo;

    while(i < 9){
        soma += digito[i] * (10 - i);
        i++;
    }

    if(soma % 11 < 2){
        decimo = 0;
    }else{
        decimo = 11 - (soma % 11);
    }

    if(decimo == digito[9]){
        return 0;
    }else{
        return 1;
    }
}

int digitoOnze(int digito[]){
    int soma = 0, i = 0, decimoPrimeiro;

    while(i < 10){
        soma += digito[i] * (11 - i);
        i++;
    }

    if(soma % 11 < 2){
        decimoPrimeiro = 0;
    }else{
        decimoPrimeiro = 11 - (soma % 11);
    }

    if(decimoPrimeiro == digito[10]){
        return 0;
    }else{
        return 1;
    }   
}

int main(){
    char cpf[15];
    int digitos[11]; 
    int i = 0, j = 0;

    scanf("%s", cpf);

    while(cpf[i]){
        if(cpf[i] >= '0' && cpf[i] <= '9'){
            digitos[j] = cpf[i] - '0';
            j++;
        }

        i++;
    }

    if(igual(digitos)){
        printf("CPF invalido: digitos iguais!");
    }else if(digitoDez(digitos) && digitoOnze(digitos)){
        printf("CPF invalido: dois digitos!");
    }else if(digitoDez(digitos)){
        printf("CPF invalido: primeiro digito!");
    }else if(digitoOnze(digitos)){
        printf("CPF invalido: segundo digito!");
    }else{
        printf("CPF valido!");
    }

    return 0;
}