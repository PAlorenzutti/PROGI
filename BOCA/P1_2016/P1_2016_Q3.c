#include<stdio.h>
#include<ctype.h>

int main(){

    char l1, l2, l3, l4;
    scanf("%c%c%c%c", &l1, &l2, &l3, &l4);

    l3 = toupper(l3);

    if(l1 >= 65 && l1 <= 90){
        if((l2 >= 48 && l2 <= 57)){
            if(l3 == 65 || l3 == 69 || l3 == 73 || l3 == 79 || l3 == 85){
                if((l4 >= 98 && l4 <= 100) || (l4 >= 102 && l4 <= 104) || (l4 >= 106 && l4 <= 110) || (l4 >= 112 && l4 <= 116) || (l4 >= 118 && l4 <= 122)){
                    printf("%c%c%c%c", l1, l2, l3, toupper(l4));
                }else{
                    printf("Invalido");
                }
            }else{
                printf("Invalido");
            }
        }else{
            printf("Invalido");
        }
    }else{
        printf("Invalido");
    }

    return 0;

}