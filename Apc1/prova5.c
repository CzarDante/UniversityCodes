#include <stdio.h>

int main(int argc, char const *argv[]){
    char numero[1000];
    scanf("%s", numero);
    int qtd_decimal =0, qtd_numeros =0;
    int i = 0;
    while(numero[i] != '\0'){
        qtd_numeros += 1;
        i++;    
    }
    i = i-i;
    while(numero[i] != '.'){
        qtd_decimal += 1;    
        i++;
    }
    for(int i = qtd_decimal+1; i <= qtd_numeros; i++){
        printf("%c", numero[i]);
    }
    for(int i = qtd_decimal; i<qtd_decimal+1;i++ ){
        printf("%c", numero[i]);
    }
    for(int i = 0; i < qtd_decimal; i++){
        printf("%c", numero[i]);
    }
    printf("\n");
    
    return 0;
}