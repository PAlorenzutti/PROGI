#include <stdio.h>
#include <locale.h>
#define mediaAprovacao 5.0

int main(){
    setlocale(LC_ALL, "portuguese_brazil");

    int turma, matricula, turmaMelhorPercentual, numeroAprovadosTurma, numeroAlunosTurma, melhorAlunoTurma, piorAlunoTurma, quantidadeNotas;
    float nota, mediaAluno, somaNotas, percentualTurmaMelhorPercentual, mediaMelhorAlunoTurma, mediaPiorAlunoTurma, percentualTurma;

    printf("\nDigite o número da turma: ");
    scanf("%d", &turma);

    percentualTurmaMelhorPercentual = 0;
    turmaMelhorPercentual = 0;

    while(turma != -1){
        numeroAlunosTurma = 0;
        numeroAprovadosTurma = 0;

        printf("\nDigite a matrícula do aluno: ");
        scanf("%d", &matricula);

        mediaMelhorAlunoTurma = -1.0;
        mediaPiorAlunoTurma = 11.0;
        melhorAlunoTurma = matricula;
        piorAlunoTurma = matricula;

        while(matricula != -1){
            numeroAlunosTurma++;
            somaNotas = 0.0;
            quantidadeNotas = 0;
            
            printf("\nDigite a nota do aluno de matrícula %d da turma %d: ", matricula, turma);
            scanf("%f", &nota);

            while(nota != -1.0){
                somaNotas += nota;
                quantidadeNotas++;

                printf("\nDigite a próxima nota: ");
                scanf("%f", &nota);
            }

            if(quantidadeNotas){
                mediaAluno = somaNotas/quantidadeNotas;
            }else{
                mediaAluno = 0;
            }

            printf("\n A média do aluno de matrícula %d é: %.2f\n", matricula, mediaAluno);

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

            printf("\nDigite a matrícula do próximo aluno da turma %d: ", turma);
            scanf("%d", &matricula);
        }

        if(melhorAlunoTurma != -1){
            printf(" \nO melhor aluno da turma %d é %d, de média %.2f\n", turma, melhorAlunoTurma, mediaMelhorAlunoTurma);
            printf(" \nO pior aluno da turma %d é %d, de média %.2f\n", turma, piorAlunoTurma, mediaPiorAlunoTurma);
        
            percentualTurma = (float)(numeroAprovadosTurma * 100)/numeroAlunosTurma;

            if(percentualTurma > percentualTurmaMelhorPercentual){
                turmaMelhorPercentual = turma;
                percentualTurmaMelhorPercentual = percentualTurma;
            }
        }

        printf("\nDigite o número da próxima turma: ");
        scanf("%d", &turma);
    }

    if(turmaMelhorPercentual != 0){
        printf("\n A turma %d possui o melhor percentual de aprovação, com %2.f%% de alunos aprovados.\n\n", turmaMelhorPercentual, percentualTurmaMelhorPercentual);  
    }

    return 0;
}