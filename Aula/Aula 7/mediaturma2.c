#include <stdio.h>
#include <locale.h>
#define mediaAprovacao 5.0

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int turma, matricula, turmaMelhorPercentual, numeroAprovadosTurma, numeroAlunosTurma, melhorAlunoTurma, piorAlunoTurma, quantidadeNotas;
    float nota, mediaAluno, somaNotas, percentualTurmaMelhorPercentual, mediaMelhorAlunoTurma, mediaPiorAlunoTurma, percentualTurma;

    printf("\nDigite o n�mero da turma: ");
    scanf("%d", &turma);

    percentualTurmaMelhorPercentual = 0;
    turmaMelhorPercentual = 0;

    while(turma != -1){
        numeroAlunosTurma = 0;
        numeroAprovadosTurma = 0;

        printf("\nDigite a matr�cula do aluno: ");
        scanf("%d", &matricula);

        mediaMelhorAlunoTurma = -1.0;
        mediaPiorAlunoTurma = 11.0;
        melhorAlunoTurma = matricula;
        piorAlunoTurma = matricula;

        while(matricula != -1){
            numeroAlunosTurma++;
            somaNotas = 0.0;
            quantidadeNotas = 0;
            
            printf("\nDigite a nota do aluno de matr�cula %d da turma %d: ", matricula, turma);
            scanf("%f", &nota);

            while(nota != -1.0){
                somaNotas += nota;
                quantidadeNotas++;

                printf("\nDigite a pr�xima nota: ");
                scanf("%f", &nota);
            }

            if(quantidadeNotas){
                mediaAluno = somaNotas/quantidadeNotas;
            }else{
                mediaAluno = 0;
            }

            printf("\n A m�dia do aluno de matr�cula %d �: %.2f\n", matricula, mediaAluno);

            if(mediaAluno >= mediaAprovacao){
                numeroAprovadosTurma++;
            }

            if(mediaAluno > mediaMelhorAlunoTurma){
                mediaMelhorAlunoTurma = mediaAluno;
                melhorAlunoTurma = matricula;
            }

            if(mediaAluno < mediaPiorAlunoTurma){
                mediaPiorAlunoTurma = mediaAluno;
                piorAlunoTurma = matricula;
            }

            printf("\nDigite a matr�cula do pr�ximo aluno da turma %d: ", turma);
            scanf("%d", &matricula);
        }

        if(melhorAlunoTurma != -1){
            printf(" \nO melhor aluno da turma %d � %d, de m�dia %.2f\n", turma, melhorAlunoTurma, mediaMelhorAlunoTurma);
            printf(" \nO pior aluno da turma %d � %d, de m�dia %.2f\n", turma, piorAlunoTurma, mediaPiorAlunoTurma);
        
            percentualTurma = (float)(numeroAprovadosTurma * 100)/numeroAlunosTurma;

            if(percentualTurma > percentualTurmaMelhorPercentual){
                turmaMelhorPercentual = turma;
                percentualTurmaMelhorPercentual = percentualTurma;
            }
        }

        printf("\nDigite o n�mero da pr�xima turma: ");
        scanf("%d", &turma);
    }

    if(turmaMelhorPercentual != 0){
        printf("\n A turma %d possui o melhor percentual de aprova��o, com %2.f%% de alunos aprovados.\n\n", turmaMelhorPercentual, percentualTurmaMelhorPercentual);  
    }

    return 0;
}