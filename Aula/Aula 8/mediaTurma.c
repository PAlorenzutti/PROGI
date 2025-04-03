#include <stdio.h>
#include <locale.h>

typedef struct{
    int curso;
    int disciplina;
    int turma;
    float media;
}tipoMediaTurma;

tipoMediaTurma atualizar(tipoMediaTurma atual, tipoMediaTurma pior){
    if(atual.media < pior.media){
        pior = atual;
    }

    return pior;
}

void apresentar(tipoMediaTurma pior){
    setlocale(LC_ALL, "portuguese_brazil");

    printf("\nCurso: %d", pior.curso);
    printf("\nDisciplina: %d", pior.disciplina);
    printf("\nTurma: %d", pior.turma);
    printf("\nMédia: %.2f", pior.media);
}

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    tipoMediaTurma atual, pior;

    printf("Digite o número do curso: ");
    scanf("%d", &atual.curso);

    pior.curso = -1;
    pior.turma = -1;
    pior.curso = -1;
    pior.media = 11;

    while(atual.curso != -1){
        printf("\nDigite o número da disciplina do curso %d: ", atual.curso);
        scanf("%d", &atual.disciplina);

        while(atual.disciplina != -1){
            printf("\nDigite o número da turma da disciplina %d do curso %d: ", atual.disciplina, atual.curso);
            scanf("%d", &atual.turma);
            
            printf("\nDigite a média da turma %d: ", atual.turma);
            scanf("%f", &atual.media);

            while(atual.turma != -1){

                printf("\nSe houver, digite o número de outra turma da disciplina %d: ", atual.disciplina);
                scanf("%d", &atual.turma);

                if(atual.turma != -1){
                    printf("\nDigite a média da turma %d: ", atual.turma);
                    scanf("%f", &atual.media);
                }else{
                    break;
                }

                pior = atualizar(atual, pior);
            }

            printf("\nSe houver, digite o número de outra disciplina do curso %d: ", atual.curso);
            scanf("%d", &atual.disciplina);
        }

        printf("\nSe houver, digite o número de outro curso: ");
        scanf("%d", &atual.curso);
    }

    if(pior.media != 11){
        printf("\nO pior curso foi:\n");

        apresentar(pior);
    }

    return 0;

}