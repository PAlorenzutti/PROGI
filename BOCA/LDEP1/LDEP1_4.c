#include<stdio.h>

int main(){

  int quantidade, resto, indice, primo, divisor;

  scanf("%d", &quantidade);

  for(primo = 2; primo <= quantidade; primo++){ //loop para aumentar n�meros primos at� a quantidade especificada.
    divisor = 0; 

    for(indice = 1; indice <= primo; indice++){ //loop para testar divisores at� o valor o primo em si
      resto = primo % indice;
      if(resto == 0){ //vai testando se o n�mero � divis�vel pelos divisores at� o primo
        divisor++;  
      }
    }

    if(divisor == 2){ //se o n�mero tiver apenas dois divisores, � primo
      printf("%d ", primo);
    }
  }

  return 0;

}
