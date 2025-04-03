#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 100
#define DELIM -1

typedef int tipoInfo;

typedef struct{
    tipoInfo info[MAX];
    tipoInfo elemento;
    int posicao;
    int n;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    printf("\nDigite um elemento diferente de -1: ");
    scanf("%d", &info);
    return info;
}

tipoLista lerLista(){
    setlocale(LC_ALL, "portuguese_brazil");

    tipoLista l;

    l.n = 0;

    l.info[l.n] = lerInfo();

    while(l.info[l.n] != DELIM){
        l.n++;
        l.info[l.n] = lerInfo();
    }

    return l;
}

void printarInfo(tipoInfo info){
    printf("%d ", info);
}

void printarLista(tipoLista l){
    int i;

    for(i = 0;i < l.n; i++){
        printarInfo(l.info[i]);
    }

    printf("\n");
}

tipoLista criarListaVazia(){
    tipoLista l;
    l.n = 0;
    return l;
}

tipoLista inserirElemento(tipoLista l){
    setlocale(LC_ALL, "portuguese_brazil");

    int i;
    
    if(l.n == MAX){
        return l;
    }

    printf("\nDigite o elemento que deseja inserir no vetor: ");
    scanf("%d", &l.elemento);

    printf("\nDigite a posição que deseja inserir no vetor: ");
    scanf("%d", &l.posicao);

    if(l.posicao >= 0 && l.posicao <= l.n){
        for(int i = l.n; i > l.posicao; i--){
            l.info[i] = l.info[i - 1];
        }

        l.info[l.posicao] = l.elemento;
        l.n++;
    }

    return l;
}

int estaVazia(tipoLista l){
    return !l.n;
}

int compararInfo(tipoInfo info1, tipoInfo info2){
    if(info1 < info2){
        return -1;
    }

    if(info1 > info2){
        return 1;
    }

    return 0;
}

int pesquisaSimples(tipoLista l){
    int i;

    for(i = 0; i < l.n; i++){
        if(!compararInfo(l.info[i], l.elemento)){
            return i;
        }
    }

    return -1;
}

int pesquisaBinaria(tipoLista l){
    int inicio, meio, final, comparar;

    inicio = 0;
    final = l.n - 1;

    while(inicio <= final){
        meio = (inicio + final) / 2;

        comparar = compararInfo(l.elemento, l.info[meio]);

        if(!comparar){
            return meio;
        }

        if(comparar > 0){
            inicio = meio + 1;
        }else{
            final = meio - 1;
        }
    }

    return -1;
}

tipoLista excluirElemento(tipoLista l){
    setlocale(LC_ALL, "portuguese_brazil");

    int i;

    for(i = l.posicao; i < l.n - 1; i++){
        l.info[i] = l.info[i + 1];
    }

    l.n--;

    return l;
}

tipoLista excluirElementoLista(tipoLista l){
    printf("\nDigite o elemento que você deseja excluir da lista: ");
    scanf("%d", &l.elemento);
    
    while(pesquisaSimples(l) != -1){
        l.posicao = pesquisaSimples(l);
        l = excluirElemento(l);
    }

    return l;
}

tipoInfo pegarElemento(tipoLista l){
    if(l.elemento >= 0 && l.elemento < l.n){
        return l.info[l.elemento];
    }

    printf("Índice inválido.");
    exit(1);
}

int menorInfo(tipoLista l, int i){
    int menor;

    menor = i;

    for(i = i + 1; i < l.n; i++){
        if(compararInfo(l.info[i], l.info[menor]) < 0){
            menor = i;
        }
    }

    return menor;
}

int maiorInfo(tipoLista l, int i){
    int maior;

    maior = i;

        for(i = i + 1; i < l.n; i++){
        if(compararInfo(l.info[i], l.info[maior]) > 0){
            maior = i;
        }
    }

    return maior;
}

tipoLista mudarPosicao(tipoLista l, int i, int j){
    tipoInfo temp;

    temp = l.info[i];
    l.info[i] = l.info[j];
    l.info[j] = temp;

    return l;
}

tipoLista ordenarCrescenteSimples(tipoLista l){
    int i, j;

    for(i = 0; i < l.n - 1; i++){
        j = menorInfo(l, i);
        l = mudarPosicao(l, i, j);
    }

    return l;
}

tipoLista ordenarDecrescenteSimples(tipoLista l){
    int i, j;

    for(i = 0; i < l.n - 1; i++){
        j = maiorInfo(l, i);
        l = mudarPosicao(l, i, j);
    }

    return l;
}

tipoLista bubbleSortCrescente(tipoLista l){
    int i, j;

    for(i = 0; i < l.n; i++){
        for(j = 0; j < l.n - 1; j++){
            if(compararInfo(l.info[j], l.info[j + 1]) > 0){
                l = mudarPosicao(l, j, j + 1);
            }
        }
    }

    return l;
}

tipoLista bubbleSortDecrescente(tipoLista l){
    int i, j;

    for(i = 0; i < l.n; i++){
        for(j = 0; j < l.n - 1; j++){
            if(compararInfo(l.info[j], l.info[j + 1]) < 0){
                l = mudarPosicao(l, j, j + 1);
            }
        }
    }

    return l;
}

tipoLista bolhaCrescente(tipoLista l){
    int ultimaTroca, houveTroca, guardaTroca, i;
    tipoInfo temp;

    ultimaTroca = l.n - 1;
    houveTroca = 1;

    while(houveTroca){
        houveTroca = 0;

        for(i = 0; i < ultimaTroca; i++){
            if(compararInfo(l.info[i], l.info[i + 1]) > 0){
                l = mudarPosicao(l, i, i + 1);
                houveTroca = 1;
                guardaTroca = i;
            }
        }

        ultimaTroca = guardaTroca;
    }

    return l;
}

tipoLista bolhaDecrescente(tipoLista l){
    int ultimaTroca, houveTroca, guardaTroca, i;
    tipoInfo temp;

    ultimaTroca = l.n - 1;
    houveTroca = 1;

    while(houveTroca){
        houveTroca = 0;

        for(i = 0; i < ultimaTroca; i++){
            if(compararInfo(l.info[i], l.info[i + 1]) < 0){
                l = mudarPosicao(l, i, i + 1);
                houveTroca = 1;
                guardaTroca = i;
            }
        }

        ultimaTroca = guardaTroca;
    }

    return l;
}

tipoLista inserirElementoOrdenado(tipoLista l){
    setlocale(LC_ALL, "portuguese_brazil");

    int i;
    
    if(l.n == MAX){
        return l;
    }

    printf("\nDigite o elemento que deseja inserir no vetor: ");
    scanf("%d", &l.elemento);

    printf("\nDigite a posição que deseja inserir no vetor: ");
    scanf("%d", &l.posicao);

    if(l.posicao >= 0 && l.posicao <= l.n){
        for(int i = l.n; i > l.posicao; i--){
            l.info[i] = l.info[i - 1];
        }

        l.info[l.posicao] = l.elemento;
        l.n++;
    }

    l = ordenarCrescenteSimples(l);

    return l;
}

int main(){
    tipoLista l;

    l = lerLista();

    l = excluirElementoLista(l);

    printarLista(l);

    return 0;
}