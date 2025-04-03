#include <stdio.h>

int verificapH(float pH);
int verificaGotaChuvaAcida(float pH);
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);
 
int main(){
    int area, den, time; // m2, gotas por m2 em t, t
    float pH = 0;

    int acid = 0, basic = 0, neut = 0, acidDrops = 0;
    float maxAcid = 7.0, maxBasic = 7.0, maxNeut = 0.0;

    scanf("%d %d %d", &area, &den, &time);
    int i = 0, gotas = area * den * time;
    float diff = 0.0, newDiff = 0.0;

    for (; i < gotas; i++){
        scanf("%f", &pH);

        if (verificapH(pH) == 1){
            if (maxAcid > pH) maxAcid = pH;
            if (verificaGotaChuvaAcida(pH) == 1) acidDrops++;
            acid++;
        }
        else if (verificapH(pH) == 2){
            if (maxBasic < pH) maxBasic = pH;
            basic++;
        }
        else { neut++; }

        diff = 7 - maxNeut;
        if (diff < 0) diff *= -1.0;
        newDiff = 7 - pH;
        if (newDiff < 0) newDiff *= -1.0;
        if (newDiff < diff) maxNeut = pH;
    }

    if (i == 0) { printf("Nenhuma gota foi avaliada"); }
    else {
        float porc = porcentagem(i, acidDrops);
        printf("%d %d %d %.2f %.2f %.2f\n", acid, basic, neut, maxAcid, maxBasic, maxNeut);
        imprimeResultadosAnalise(porc, 100.0 - porc);
    }

    return 0;
}

int verificapH(float pH){
    return (pH < 7.0) ? 1 : (pH > 7.0) ? 2 : 0;
}

int verificaGotaChuvaAcida(float pH){
    return (pH < 5.7);
}

float porcentagem(float total, float valor){
    return (valor/total * 100);
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal){
    if (porcentagemGotasChuvaAcida > 75.0) printf("Chuva Acida %0.2f%% %0.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    else if (porcentagemGotasChuvaNormal >= 75.0) printf("Chuva Normal %0.2f%% %0.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    else printf("Chuva com indicios de chuva acida %0.2f%% %0.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
}