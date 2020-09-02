/*Organizao as iniciais dos nomes por ordem alfabetica */ 
#include <stdio.h>

int main(int argc, char const *argv[]){
    char nomes[1000000];
    scanf("%s", nomes);
    int i =0, qtd_nomes = 0, aux;
    while(nomes[i] != '\0'){
        qtd_nomes += 1;
        i++;
    }
    for(int j = 0; j < qtd_nomes; j++){
        for(int i =0; i < qtd_nomes; i++){
            if(nomes[i] > nomes[i+1]){
                aux = nomes[i];
                nomes[i] = nomes[i+1];
                nomes[i+1] = aux;
            }
        }
    }
    for(int i = 0; i<=qtd_nomes; i++){
        printf("%c", nomes[i]);
    }
    printf("\n");

    return 0;
}