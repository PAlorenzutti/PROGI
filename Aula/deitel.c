#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    int conta;
    char nome[30];
    double balanco;

    FILE *fw;

    if(!(fw = fopen("clientes.txt", "r"))){
        printf("O arquivo não pode ser aberto e lido.");
    }else{
        printf("%-10s %-13s %s\n", "conta", "nome", "balanco");

        while(!feof(fw)){
            fscanf(fw, "%d %s %lf", &conta, nome, &balanco);
            printf("%-10d%-13s%7.2f\n", conta, nome, balanco);

        }

        fclose(fw);
    }

    return 0;
}