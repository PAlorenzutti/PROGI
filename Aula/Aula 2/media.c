#include<stdio.h>
#include<locale.h>

int main(){
    
    setlocale(LC_ALL, "Portuguese_Brazil");

    float t1, t2, p1, p2, media, final;
    printf("\nDigite as notas dos trabalho 1 e 2, respectivamente:\n");
    scanf("%f%f", &t1, &t2);
    printf("\nDigite as notas dos trabalho 1 e 2, respectivamente:\n");
    scanf("%f%f", &p1, &p2);

    media = 0.4 * p1 + 0.4 * p2 + 0.1 * t1 + 0.1 * t2;

    if(media <= 7){
        printf("\nSua média foi %.2f, portanto você está de final.\n\nDigite a nota da prova final:\n", media);
        scanf("%f", &final);

        if((final + media)/2 >= 5){
            printf("\nSua média final foi %.2f, portanto você está aprovado.\n\n", (final + media)/2);
        }else{
            printf("\nSua média final foi %.2f, portanto você está reprovado.\n\n", (final + media)/2);
        }
    }else{
        printf("Sua média foi %.2f, portanto você está aprovado.\n\n", media);
    }

    return 0;

}