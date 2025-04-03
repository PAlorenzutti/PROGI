#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y, z;
} tipoPonto;

tipoPonto lerPonto() {
    tipoPonto p;

    printf("\nDigite as coordenadas (x, y, z) do ponto: ");

    scanf("%f", &p.x);
    scanf("%f", &p.y);
    scanf("%f", &p.z);
    return p;
}

void escrevePonto(tipoPonto p) {
    printf("(%.2f, %.2f, %.2f)", p.x, p.y, p.z);
}

float distanciaPontos(tipoPonto p, tipoPonto q) {
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2) + pow(p.z - q.z, 2));
}

typedef struct {
    tipoPonto i, f;
    //armazena as coordenadas do ponto inicial e final da linha.
} tipoLinha;

tipoLinha criarLinha(tipoPonto p, tipoPonto q) {
    tipoLinha L;
    L.i = p;
    L.f = q;
    //pega os pontos inicial e final de uma linha.
    return L;
}

float tamanhoLinha(tipoLinha L) {
    return distanciaPontos(L.i, L.f);
}

tipoLinha maiorLinha(tipoLinha l1, tipoLinha l2) {
    float t1, t2;
    t1 = tamanhoLinha(l1);
    t2 = tamanhoLinha(l2);

    if(t1 > t2){
        return l1;
    } else {
        return l2;
    }
}

void escreverMaiorLinha(tipoLinha L) {
    printf("\nA maior linha vai de ");
    escrevePonto(L.i);
    printf(" a ");
    escrevePonto(L.f);
    printf(" e mede: %.2f\n", tamanhoLinha(L));
}

int main() {
    tipoPonto p, q, r;
    tipoLinha l1, l2, l3, maior;

    p = lerPonto();
    q = lerPonto();
    r = lerPonto(); // Corrija a variável r aqui, que estava incorretamente atribuída a q.

    l1 = criarLinha(p, q);
    l2 = criarLinha(q, r);
    l3 = criarLinha(p, r);

    maior = maiorLinha(l1, l2);
    maior = maiorLinha(maior, l3);

    escreverMaiorLinha(maior);

    return 0;
}
