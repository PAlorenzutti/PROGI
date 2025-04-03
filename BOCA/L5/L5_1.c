#include <stdio.h>
#include <math.h>

#define MEDIA 70

typedef int tipoInfo;

typedef struct{
    tipoInfo *nota;
    int quantidadeNotas;
    tipoInfo menor;
    tipoInfo maior;
    float media;
    float desvio;
    int aprovados;
    int reprovados;
}tipoLista;

tipoInfo lerInfo(){
    tipoInfo info;
    scanf("%d", &info);
    return info;
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

int menorInfo(tipoLista l, int i){
    int menor;

    menor = i;

    for(i = i + 1; i < l.quantidadeNotas; i++){
        if(compararInfo(l.nota[i], l.nota[menor]) < 0){
            menor = i;
        }
    }

    return menor;
}

int maiorInfo(tipoLista l, int i){
    int maior;

    maior = i;

        for(i = i + 1; i < l.quantidadeNotas; i++){
        if(compararInfo(l.nota[i], l.nota[maior]) > 0){
            maior = i;
        }
    }

    return maior;
}

tipoLista mudarPosicao(tipoLista l, int i, int j){
    tipoInfo temp;

    temp = l.nota[i];
    l.nota[i] = l.nota[j];
    l.nota[j] = temp;

    return l;
}

tipoLista ordenarCrescenteSimples(tipoLista l){
    int i, j;

    for(i = 0; i < l.quantidadeNotas - 1; i++){
        j = menorInfo(l, i);
        l = mudarPosicao(l, i, j);
    }

    l.menor = l.nota[0];
    l.maior = l.nota[l.quantidadeNotas - 1];

    return l;
}

tipoLista calcularMedia(tipoLista l){
    int i;
    float media, soma;

    soma = 0;

    for(i = 0; i < l.quantidadeNotas; i++){
        soma += l.nota[i];
    }

    l.media = (float) soma / l.quantidadeNotas;

    return l;
}

tipoLista calcularDesvio(tipoLista l){
    int i;
    float soma;

    soma = 0;

    for(i = 0; i < l.quantidadeNotas; i++){
        soma += pow(l.nota[i] - l.media, 2);
    }

    l.desvio = sqrt(soma / l.quantidadeNotas);

    return l;
}

tipoLista aprovados(tipoLista l){
    int i;

    l.aprovados = 0;

    for(i = 0; i < l.quantidadeNotas; i++){
        if(l.nota[i] > l.media){
            l.aprovados++;
        }
    }

    return l;
}

tipoLista reprovados(tipoLista l){
    int i;

    l.reprovados = 0;

    for(i = 0; i < l.quantidadeNotas; i++){
        if(l.nota[i] < MEDIA){
            l.reprovados++;
        }
    }

    return l;
}

void printarLista(tipoLista l){
    int i;
    
    printf("MENOR:%d, ", l.menor);
    printf("MAIOR:%d, ", l.maior);
    printf("MEDIA:%.2f, ", l.media);
    printf("STD:%.2f, ", l.desvio);
    printf("ACIMA_MEDIA_CONC:%d, ", l.aprovados);
    printf("REPROV:%d", l.reprovados);
}

int main(){
    tipoLista l;
    int i;

    scanf("%d", &l.quantidadeNotas);

    tipoInfo notas[l.quantidadeNotas];

    for(i = 0; i < l.quantidadeNotas; i++){
        notas[i] = lerInfo();
    }

    l.nota = notas;

    l = ordenarCrescenteSimples(l);

    l = calcularMedia(l);

    l = calcularDesvio(l);

    l = aprovados(l);

    l = reprovados(l);

    printarLista(l);

    return 0;
}