#include <stdio.h>

int main(){
    int dias = 0, horas, minutos, adicional;

    scanf("%d:%d %d", &horas, &minutos, &adicional);

    if(minutos + adicional > 60){
        horas = horas + ((minutos + adicional) / 60);
        minutos = (minutos + adicional) - 60;

        while(minutos > 60){
            minutos = minutos - 60;
        }

        while(horas > 24){
            horas = horas - 24;
            dias++;
        }
    }else{
        minutos = minutos + adicional;
    }

    if(dias > 0 && dias < 2){
        if(horas < 2){
            if(minutos < 2){
                printf("(%d dia)(%d hora)(%d minuto)", dias, horas, minutos);
            }else{
                printf("(%d dia)(%d hora)(%d minutos)", dias, horas, minutos);
            }
        }else{
            if(minutos < 2){
                printf("(%d dia)(%d horas)(%d minuto)", dias, horas, minutos);
            }else{
                printf("(%d dia)(%d horas)(%d minutos)", dias, horas, minutos);
            }
        }
    }else if(dias >= 2){
        if(horas < 2){
            if(minutos < 2){
                printf("(%d dias)(%d hora)(%d minuto)", dias, horas, minutos);
            }else{
                printf("(%d dias)(%d hora)(%d minutos)", dias, horas, minutos);
            }
        }else{
            if(minutos < 2){
                printf("(%d dias)(%d horas)(%d minuto)", dias, horas, minutos);
            }else{
                printf("(%d dias)(%d horas)(%d minutos)", dias, horas, minutos);
            }
        }
    }else{
        if(horas < 2){
            if(minutos < 2){
                printf("(%d hora)(%d minuto)", horas, minutos);
            }else{
                printf("(%d hora)(%d minutos)", horas, minutos);
            }
        }else{
            if(minutos < 2){
                printf("(%d horas)(%d minuto)", horas, minutos);
            }else{
                printf("(%d horas)(%d minutos)", horas, minutos);
            }
        }
    }

    return 0;
}