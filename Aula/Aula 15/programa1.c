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

tipoLista mudarPosicao(tipoLista l, int i, int j){
    tipoInfo temp;

    temp = l.produto[i];
    l.produto[i] = l.produto[j];
    l.produto[j] = temp;

    return l;
}

tipoLista ordenarCrescente(tipoLista l){
    int i, j;

    for(i = 0; i < l.qtdProdutos; i++){
        for(j = 0; j < l.qtdProdutos - 1; j++){
            if(l.produto[j].preco > l.produto[j + 1].preco){
                l = mudarPosicao(l, j, j + 1);
            }else if((l.produto[j].preco == l.produto[j + 1].preco) && (l.produto[j].qtd > l.produto[j + 1].qtd)){
                l = mudarPosicao(l, j, j + 1);
            }else if((l.produto[j].preco == l.produto[j + 1].preco) && (l.produto[j].qtd == l.produto[j + 1].qtd) && (l.produto[j].id > l.produto[j + 1].id)){
                l = mudarPosicao(l, j, j + 1);
            }
        }
    }

    return l;
}

void fazerCadastro(){
    FILE *fw;
    tipoLista l;

    if(!(fw = fopen("cadastro.txt", "w"))){
        printf("Erro");
        exit(1);
    }

    int i = 0;
    l.qtdProdutos = 0;

    while((scanf("%d %d %f ", &l.produto[i].id, &l.produto[i].qtd, &l.produto[i].preco)) != EOF){
        fgets(l.produto[i].nome, 50, stdin);
        fprintf(fw, "%d %d %.2f %s", l.produto[i].id, l.produto[i].qtd, l.produto[i].preco, l.produto[i].nome);
        i++;
        l.qtdProdutos++;
    }

    fclose(fw);

    exit(1);
}

tipoLista lerCadastro(){
    FILE *fr;
    tipoLista l;

    if(!(fr = fopen("cadastro.txt", "r"))){
        fazerCadastro();
    }

    int i = 0;

    while(!(feof(fr))){
        fscanf(fr, "%d %d %f ", &l.produto[i].id, &l.produto[i].qtd, &l.produto[i].preco);
        fgets(l.produto[i].nome, 50, fr);
        i++;
        l.qtdProdutos++;
    }

    fclose(fr);

    return l;
}

int pesquisaId(tipoLista l, int idDelete){
    int i;

    for(i = 0; i < l.qtdProdutos; i++){
        if(l.produto[i].id == idDelete){
            return i;
        }
    }

    return -1;
}

tipoLista excluirProduto(tipoLista l){
    setlocale(LC_ALL, "portuguese_brazil");

    int idDelete, posicao, i;

    printf("Digite o id do produto que deseja excluir da lista: ");
    scanf("%d", &idDelete);

    posicao = pesquisaId(l, idDelete);

    if(posicao == -1){
        printf("O produto não está na lista.\n");
        return l;
    }

    for(i = posicao; i < l.qtdProdutos - 1; i++){
        l.produto[i] = l.produto[i + 1];
    }

    l.qtdProdutos--;

    return l;
}

void salvarBinario(tipoLista l){
    FILE *fwb;

    if(!(fwb = fopen("cadastro.bin", "wb"))){
        printf("Erro.");
        exit(1);
    }

    fwrite(&l, sizeof(tipoLista), 1, fwb);

    fclose(fwb);
}

void printarLista(tipoLista l){
    int i;

    for(i = 0; i < l.qtdProdutos; i++){
        printf("%d %d %.2f %s", l.produto[i].id, l.produto[i].qtd, l.produto[i].preco, l.produto[i].nome);
    }
}


int main(){
    tipoLista l;

    l = lerCadastro();

    ordenarCrescente(l);

    l = excluirProduto(l);

    salvarBinario(l);

    printarLista(l);
    
    return 0;
}