#include <stdio.h>
#include <string.h>

int atoi(char texto){
    int j;

    j = texto - '0';

    return j;
}

void pegarParteDois(char saida[], char parteDois[], int i){
    int j = 0;
    
    while(saida[i]){
        parteDois[j] = saida[i];
        i++;
        j++;
    }

    parteDois[j] = '\0';
}

void removerAspas(char entrada[], char saida[]){
    int i = 0, j = 0;
    int tamanho = strlen(entrada) - 4;

    while(i < tamanho){
        saida[j] = entrada[i + 2];
        j++;
        i++;
    }

    saida[j] = '\0';
}

void trocarPorc(char saida[], int numeros[], int quantidade){
    int i = 0, numero, vetor;
    char parteUm[300];
    char parteDois[300];
    char adicional[10];
    char erro[] = "ERRO";
    
    while(saida[i]){
        if((saida[i] == '%') && (atoi(saida[i + 1]) <= quantidade) && (atoi(saida[i + 1]) >= 1)){
            vetor = atoi(saida[i + 1]) - 1;
            sprintf(adicional, "%d", numeros[vetor]);
            pegarParteDois(saida, parteDois, i + 2);
            strcat(parteUm, adicional);
            strcat(parteUm, parteDois);
            strcpy(saida, parteUm);
        }else if((saida[i] == '%')){
            pegarParteDois(saida, parteDois, i + 2);
            strcat(parteUm, erro);
            strcat(parteUm, parteDois);
            strcpy(saida, parteUm);
        }else{
            parteUm[i] = saida[i];
            parteUm[i + 1] = '\0';
        }

        i++;
    }
}

int main(){
    int quantidade; 
    char entrada[300];
    char saida[300];
    
    scanf("%d", &quantidade);

    int numeros[quantidade];

    int j = 0;

    while(j < quantidade){
        scanf("%d", &numeros[j]);
        j++;
    }
    
    fgets(entrada, 300, stdin);

    removerAspas(entrada, saida);

    trocarPorc(saida, numeros, quantidade);

    printf("%s", saida);

    return 0;
}