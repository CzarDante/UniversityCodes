#include <stdio.h>
#include <string.h>

int main (){
    char nome[50];
    int qtd_letras = 0;
    fgets(nome,50,stdin);
    for(int i=0;i<50;i++){
        if(nome[i]!= '\0'){
            qtd_letras++;
        }
    }
    printf("%d\n", qtd_letras);

    return 0;
}