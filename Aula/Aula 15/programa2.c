#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int id;
    int qtd;
    float preco;
    char nome[50];
}tipoInfo;

typedef struct{
    tipoInfo produto[100];
    int qtdProdutos;
}tipoLista;

tipoLista lerBinario(){
    FILE *frb;
    tipoLista l;

    if(!(frb = fopen("cadastro.bin", "rb"))){
        printf("Erro");
        exit(1);
    }

    fread(&l, sizeof(tipoLista), 1, frb);

    fclose(frb);

    return l;
}

void atualizarLista(tipoLista l){
    int j = 0;
    
    while((scanf("%d %d %f ", &l.produto[l.qtdProdutos].id, &l.produto[l.qtdProdutos].qtd, &l.produto[l.qtdProdutos].preco)) != EOF){
        fgets(l.produto[l.qtdProdutos].nome, 50, stdin);
        l.qtdProdutos++;
        j++;
    }

    int i;
    FILE *fw;

    if(!(fw = fopen("cadastroAtualizado.txt", "w"))){
        printf("Erro");
        exit(1);
    }

    for(i = 0; i < l.qtdProdutos; i++){
        if(i == l.qtdProdutos - j){
            fprintf(fw, "\n");
        }

        fprintf(fw, "%d %d %.2f %s", l.produto[i].id, l.produto[i].qtd, l.produto[i].preco, l.produto[i].nome);
    }

    fclose(fw);
}

int main(){
    tipoLista l;

    l = lerBinario();

    atualizarLista(l);

    return 0;
}