#include<stdio.h>

int main(){

  int quantidade, resto, indice, primo, divisor;

  scanf("%d", &quantidade);

  for(primo = 2; primo <= quantidade; primo++){ //loop para aumentar números primos até a quantidade especificada.
    divisor = 0; 

    for(indice = 1; indice <= primo; indice++){ //loop para testar divisores até o valor o primo em si
      resto = primo % indice;
      if(resto == 0){ //vai testando se o número é divisível pelos divisores até o primo
        divisor++;  
      }
    }

    if(divisor == 2){ //se o número tiver apenas dois divisores, é primo
      printf("%d ", primo);
    }
  }

  return 0;

}
