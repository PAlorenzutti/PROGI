#include <stdio.h>
#include <locale.h>
#define MAX 100

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int numero[MAX];
    int i, j;

    i = 0;

    printf("\nDigite o %d° número: ", i + 1);
    scanf("%d", &numero[i]);

    
    while(numero[i] > -1 && i < MAX){
        i++;

        printf("\nDigite o %d° número: ", i + 1);
        scanf("%d", &numero[i]);
    }

    int auxiliar;
    int contador = 1;

    //Algoritmo Bubble Sort em ordem crescente.
    while(contador < i){
        j = 0;

        while(j < i - 1){
            if(numero[j] < numero[j + 1]){
                auxiliar = numero[j + 1];
                numero[j + 1] = numero[j];
                numero[j] = auxiliar;
            }

            j++;
        }

        contador++;
    }

    j = 0;

    printf("\nOs 10 maiores números da sequência de naturais lida são:\n");

    while(j < 10){
        printf("%d ", numero[j]);
        j++;
    }

    return 0;
}