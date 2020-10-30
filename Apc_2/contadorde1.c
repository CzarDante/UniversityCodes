#include <stdio.h>
#include <string.h>

int main (){
    char numero[50];
    printf("Digite o numero: ");
    fgets(numero,50,stdin);
    int qtd_numeros = strlen(numero);
    int qtd_1s = 0;
    for(int i=0;i<50;i++){
        if(numero[i] == '1'){
            qtd_1s++;
        }
    }
    printf("A quantidade de 1's: %d",qtd_1s);

    return 0;
}