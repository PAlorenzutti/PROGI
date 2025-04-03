#include<stdio.h>

int main()
{
    char frase;
    scanf("%c", &frase);

    printf("RESP:");

    while(1){
        if(frase != ' '){
            printf("%c", frase);  
        }

        if(frase == '.' || frase == '?' || frase == '!'){
            break;
        }

        scanf("%c", &frase);
    }

    return 0;
}
