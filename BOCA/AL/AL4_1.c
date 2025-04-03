#include <stdio.h>
#include<math.h>

int enesimoPrimo(int n){

    int i, j = 0, primo, divisor;

    for(primo = 2; j < n; primo++){

        divisor = 0;

        for(i = 1; i <= primo; i++){
            if(primo % i == 0){
                divisor++;
            }
        }

        if(divisor == 2){
            j++;
        }

    }

    return primo - 1;

}

int enesimoTermo(int n){

    int termo1 = 0, termo2 = 1, termo3 = 2, aux;

    if(n <= 0){
        printf("\n");
        return 0;
    }else if(n == 1){
        return termo1;
        n--;
    }else if(n == 2){
        return termo2;
        n--;
    }else if(n == 3){
        return termo3;
        n--;
    }else{
        while(n > 3){
            aux = (termo3 * termo2) - termo1;
            termo1 = termo2;
            termo2 = termo3;
            termo3 = aux;   
            n--;
        }
        return termo3;
    }

}

int enesimaPotencia(int m, int n){

    int resultado;

    resultado = pow(m, n);

    return resultado;

}

int enesimoMultiploComum(int n, int num1, int num2){

    int aux, mmc;

    if(num1 > num2){
        aux = num1;
    }else{
        aux = num2;
    }

    mmc = aux;

    while(1){
        if(mmc % num1 == 0 && mmc % num2 == 0){
            break;
        }
        mmc++;
    }

    mmc = n * mmc;

    return mmc;   
    
}

int main(){

    int opc, n, num1, num2, result;
    scanf("%d", &opc);

    while (opc){
        switch (opc) {
            case 1:
                scanf ("%d", &n);
                result = enesimoPrimo(n);
                printf("%d ", result);
                break;
            case 2: 
                scanf ("%d", &n);
                result = enesimoTermo(n);
                printf("%d ", result);
                break;
            case 3:
                scanf ("%d%d", &num1, &num2);
                result = enesimaPotencia(num1, num2);
                printf("%d ", result);
                break;
            case 4:
                scanf ("%d%d%d", &n, &num1, &num2);
                result = enesimoMultiploComum(n, num1, num2);
                printf("%d ", result);
                break;
            default:
                printf("Opcao Invalida!\n");
        }
        scanf ("%d", &opc);
    }

    return 0;
    
}