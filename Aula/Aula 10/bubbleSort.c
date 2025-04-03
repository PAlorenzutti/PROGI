#include <stdio.h>
#include <locale.h>
#define MAX 100

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int numero[MAX];
    int i, j;

    i = 0;

    printf("\nDigite o %d� n�mero: ", i + 1);
    scanf("%d", &numero[i]);

    
    while(numero[i] > -1 && i < MAX){
        i++;

        printf("\nDigite o %d� n�mero: ", i + 1);
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

    printf("\nOs 10 maiores n�meros da sequ�ncia de naturais lida s�o:\n");

    while(j < 10){
        printf("%d ", numero[j]);
        j++;
    }

    return 0;
}