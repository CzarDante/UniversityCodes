#include <stdio.h>
#include <string.h>

int main(){    
    char nome[50];
    printf("Digite o nome: ");
    fgets(nome, 50, stdin);
    int qtd_vogais = 0;
    for(int i=0;i<50;i++){
        if(nome[i]=='a' || nome[i]=='e' || nome[i]=='i' || nome[i]=='o' || nome[i]=='u' || nome[i]=='A' || nome[i]=='E' || nome[i]=='I' || nome[i]=='O' || nome[i]=='U'){
            qtd_vogais++;
        } 
    }
    printf("quantidade: %d\n", qtd_vogais);
    return 0;
}