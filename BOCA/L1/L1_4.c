#include<stdio.h>
#include<math.h>

int main(){

    float pi = 3.141592;
    float raio, area, metade;

    scanf("%f", &raio);

    area = pow(raio, 2)*pi;

    metade = sqrt((area/2)/pi);

    printf("%.2f %.2f", area, metade);

    return 0;

}