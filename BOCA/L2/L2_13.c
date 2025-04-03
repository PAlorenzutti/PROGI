#include <stdio.h>
#include <ctype.h>

int main(){
    char frase;
    scanf("%c", &frase);
    
    while(1){
        printf("%c", toupper(frase));

        if(frase == '.' || frase == '?' || frase == '!'){
            break;
        }

        scanf("%c", &frase);
    }

    return 0;
}