#include <stdio.h>
#include <ctype.h>

int main(){
    char c1[4];
    char c2[4];
    int i;

    scanf("%s %s", c1, c2);

    i = 0;

    while(i < 3){
        if(!isalnum(c1[i]) || !isalnum(c2[i])){
            printf("Codigo invalido!");

            return 0;
        }

        i++;
    }

    i = 0;

    while(i < 3){
        if(c1[i] == c2[i]){
            printf("I");
        }else if((c1[i] == c2[i] - 32) || (c1[i] == c2[i] +32)){
            printf("C");
        }else{
            printf("D");
        }

        i++;
    }

    return 0;
}
