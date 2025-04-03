#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char clubes[25][30];
    int placar[2];
    int partidas[25];
    int pontos[25];
    int vitorias[25];
    int golsPro[25];
    int golsContra[25];
    int saldoGols[25];
    float eficiencia[25];
}tipoTime;

tipoTime zerarListas(tipoTime geral){
    int i = 0;

    for(i = 0; i < 25; i++){
        geral.partidas[i] = 0;
        geral.pontos[i] = 0;
        geral.vitorias[i] = 0;
        geral.golsPro[i] = 0;
        geral.golsContra[i] = 0;
        geral.saldoGols[i] = 0;
        geral.eficiencia[i] = 0.00;
    }

    return geral;
}

void padronizarTime(char time[]){
    int i = 0;
    
    while(time[i]){
        if(i == 0){
            time[i] = toupper(time[i]);
        }else{
            time[i] = tolower(time[i]);
        }

        i++;
    }
}

int pesquisarTime(tipoTime geral, char time[], int idTime){
    int i = 0;
    
    while(i < idTime){
        if(strcmp(time, geral.clubes[i]) == 0){
            return i;
        }

        i++;
    }

    return -1;
}

tipoTime atualizarTimes(tipoTime geral, char time[], int idTime){
    //Adiciona ou mantém o nome do time na posição do vetor clube;
    strcpy(geral.clubes[idTime], time);

    //Aumenta o número de partidas do clube;
    geral.partidas[idTime]++;

    //Se o clube ganhar, aumentar o número de pontos em 3 e o número de vitórias em 1;
    if(geral.placar[0] > geral.placar[1]){
        geral.pontos[idTime] += 3;
        geral.vitorias[idTime] += 1;
    }

    //Se o clube empatar, aumenta o número de pontos em 1;
    if(geral.placar[0] == geral.placar[1]){
        geral.pontos[idTime] += 1;
    }
    //Se o clube perder, não faz nada.

    //Soma placar 0 ao golsPro do time;
    geral.golsPro[idTime] += geral.placar[0];
    geral.golsContra[idTime] += geral.placar[1];
    //Soma placar 1 ao golsContra do time;

    //Soma ao saldo de gols do time a diferença entre placar 0 e placar 1;
    geral.saldoGols[idTime] += (geral.placar[0] - geral.placar[1]);

    return geral;
}

tipoTime calcularEficiencia(tipoTime geral, int idTime){
    int i;

    for(i = 0; i < idTime; i++){
        geral.eficiencia[i] = (geral.pontos[i]/(geral.partidas[i] * 3.0)) * 100;
    }

    return geral;
}

void apresentarTimes(tipoTime geral, int idTime){
    int i = 0;

    while(i < idTime){
        printf("%d: %s ", i + 1, geral.clubes[i]);
        printf("Pontos: %d ", geral.pontos[i]);
        printf("Vitorias: %d ", geral.vitorias[i]);
        printf("Pro: %d ", geral.golsPro[i]);
        printf("Contra: %d ", geral.golsContra[i]);
        printf("Saldo: %d ", geral.saldoGols[i]);
        printf("Eficiencia: %.2f%%", geral.eficiencia[i]);
        printf("\n");

        i++;
    }
}

tipoTime trocarPosicao(tipoTime geral, int j){
    int numeroTemp;
    float floatTemp;
    char nomeTemp[30];

    //Trocar os nomes de posição
    strcpy(nomeTemp, geral.clubes[j]);
    strcpy(geral.clubes[j], geral.clubes[j + 1]);
    strcpy(geral.clubes[j + 1], nomeTemp);

    //Trocar os pontos de posição;
    numeroTemp = geral.pontos[j];
    geral.pontos[j] = geral.pontos[j + 1];
    geral.pontos[j + 1] = numeroTemp;

    //Trocar vitórias de posição;
    numeroTemp = geral.vitorias[j];
    geral.vitorias[j] = geral.vitorias[j + 1];
    geral.vitorias[j + 1] = numeroTemp;

    //Trocar golsPro de posição;
    numeroTemp = geral.golsPro[j];
    geral.golsPro[j] = geral.golsPro[j + 1];
    geral.golsPro[j + 1] = numeroTemp;

    //Trocar golsContra de posição;
    numeroTemp = geral.golsContra[j];
    geral.golsContra[j] = geral.golsContra[j + 1];
    geral.golsContra[j + 1] = numeroTemp;   

    //Trocar saldoGols de posição;
    numeroTemp = geral.saldoGols[j];
    geral.saldoGols[j] = geral.saldoGols[j + 1];
    geral.saldoGols[j + 1] = numeroTemp;      

    //Trocar eficiência de posição;
    floatTemp = geral.eficiencia[j];
    geral.eficiencia[j] = geral.eficiencia[j + 1];
    geral.eficiencia[j + 1] = floatTemp;    

    return geral;     
}

tipoTime ordenarLista(tipoTime geral, int idTime){
    int i, j, temp;

    for(i = 0; i < idTime; i++){
        for(j = 0; j < idTime - 1; j++){
            if(geral.pontos[j] < geral.pontos[j + 1]){
                geral = trocarPosicao(geral, j);
            }else if(geral.pontos[j] == geral.pontos[j + 1] && geral.vitorias[j] < geral.vitorias[j + 1]){
                geral = trocarPosicao(geral, j);
            }else if(geral.pontos[j] == geral.pontos[j + 1] && geral.vitorias[j] == geral.vitorias[j + 1] && geral.saldoGols[j] < geral.saldoGols[j + 1]){
                geral = trocarPosicao(geral, j);
            }else if(geral.pontos[j] == geral.pontos[j + 1] && geral.vitorias[j] == geral.vitorias[j + 1] && geral.saldoGols[j] == geral.saldoGols[j + 1] && geral.golsPro[j] < geral.golsPro[j + 1]){
                geral = trocarPosicao(geral, j);
            }else if(geral.pontos[j] == geral.pontos[j + 1] && geral.vitorias[j] == geral.vitorias[j + 1] && geral.saldoGols[j] == geral.saldoGols[j + 1] && geral.golsPro[j] == geral.golsPro[j + 1]){
                if(strcmp(geral.clubes[j], geral.clubes[j + 1]) > 0){
                    geral = trocarPosicao(geral, j);
                };
            }
        }
    }

    return geral;
}

int main(){
    tipoTime geral;
    char time1[30];
    char time2[30];
    int idTime = 0;
    int tempPlacar;

    //Inicializar as listas que envolvem números estátisticos em zero.
    geral = zerarListas(geral);

    while(scanf("%s %d %s %d", time1, &geral.placar[0], time2, &geral.placar[1]) != EOF){
        padronizarTime(time1);
        padronizarTime(time2);

        if(pesquisarTime(geral, time1, idTime) == -1){
            geral = atualizarTimes(geral, time1, idTime);
            idTime++;
        }else{
            geral = atualizarTimes(geral, time1, pesquisarTime(geral, time1, idTime));
        }

        //Trocar placares:
        tempPlacar = geral.placar[0];
        geral.placar[0] = geral.placar[1];
        geral.placar[1] = tempPlacar;

        if(pesquisarTime(geral, time2, idTime) == -1){
            geral = atualizarTimes(geral, time2, idTime);
            idTime++;
        }else{
            geral = atualizarTimes(geral, time2, pesquisarTime(geral, time2, idTime));
        }
    }

    //Calcular a eficiência de todos os clubes
    geral = calcularEficiencia(geral, idTime);

    geral = ordenarLista(geral, idTime);

    apresentarTimes(geral, idTime);

    return 0;
}